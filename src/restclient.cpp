#include "restclient.hpp"

#include <qcontainerfwd.h>
#include <qlogging.h>
#include <qloggingcategory.h>
#include <QLoggingCategory>
#include <QMetaEnum>
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include <QNetworkReply>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qrestaccessmanager.h>
#include <QRestReply>
#include <qstringliteral.h>
#include <qurl.h>

#include "apiresources.hpp"
#include "issues/issue.hpp"
#include "tl/expected.hpp"

Q_LOGGING_CATEGORY(lcRestClient, "redmine.restclient")
namespace redmine {

RestClient::RestClient(QObject* parent)
    : m_manager(new QRestAccessManager(new QNetworkAccessManager(this), this)), m_connected(false), QObject(parent) {}

bool RestClient::connect() {
    if (m_baseUrl.isEmpty()) {
        qWarning(lcRestClient()) << tr("Base url is not set. Could not connect");
        return false;
    }
    if (m_apiKey.isEmpty()) {
        qWarning(lcRestClient()) << tr("Api key is not set. Could not connect");
        return false;
    }
    if (nullptr == m_manager) {
        qWarning(lcRestClient()) << tr("No valid instance for QNetworkAccessManager, abort!");
        return false;
    }
    emit aboutToConnect();
    QNetworkRequest request(m_baseUrl);
    auto* reply = m_manager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, this, [&]() {
        setConnected(true);
        reply->deleteLater();
    });
    QObject::connect(reply, &QNetworkReply::errorOccurred, this, [&](const auto error) {
        QMetaEnum metaEnum = QMetaEnum::fromType<QNetworkReply::NetworkError>();

        qWarning(lcRestClient()) << tr("Failed to connect to URL: ") << m_baseUrl << tr(" with error code: ")
                                 << metaEnum.valueToKey(error);
        setConnected(false);
        reply->deleteLater();
    });

    return true;
}

bool RestClient::connect(const QUrl& baseUrl, const QString& apiKey) {
    setBaseUrl(baseUrl);
    setApiKey(apiKey);
    return connect();
}

void RestClient::setBaseUrl(const QUrl& newUrl) {
    if (newUrl == m_baseUrl) {
        return;
    }
    m_baseUrl = newUrl;
    emit baseUrlChanged();
}

void RestClient::setApiKey(const QString& newApiKey) {
    if (newApiKey == m_apiKey) {
        return;
    }
    m_apiKey = newApiKey;
    emit apiKeyChanged();
}

bool RestClient::isConnected() const {
    return m_connected;
}

void RestClient::setConnected(bool newConnected) {
    if (m_connected == newConnected) {
        return;
    }
    m_connected = newConnected;
    emit connectedChanged();
}

tl::expected<QNetworkRequest, QString> RestClient::createRequest(const QString& endpoint, const QUrlQuery& query) {
    if (!m_connected) {
        qWarning(lcRestClient()) << tr(
            "Client does not seem to be connected, please call \'RestClient::connect()\' first");
        return tl::unexpected<QString>(
            "Client does not seem to be connected, please call \'RestClient::connect()\' first");
    }
    QUrl url(m_baseUrl.toString() + endpoint + "?" + query.toString());
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(g_Authentication, m_apiKey.toUtf8());
    return request;
}

void RestClient::getIssue(quint32 issueId) {
    auto req = createRequest(api_resources::ISSUE.arg(issueId));
    if (!req.has_value()) {
        qWarning(lcRestClient()) << tr("Failed to create request with error: ") << req.error();
        emit errorOccurred(req.error());
    }

    m_manager->get(req.value(), this, [this](QRestReply& reply) {
        if (!reply.isSuccess()) {
            qWarning(lcRestClient()) << tr("reply does not sucseeded with reason: ") << reply.error();
        }
        if (std::optional json = reply.readJson()) {
            Issue issue;
            issue.setJsonData(json.value());
        }
    });
}

} // namespace redmine
