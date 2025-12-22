#include "restclient.hpp"

#include <qcontainerfwd.h>
#include <qlogging.h>
#include <qloggingcategory.h>
#include <QLoggingCategory>
#include <qnetworkaccessmanager.h>
#include <qobject.h>
#include <qrestaccessmanager.h>
#include <qurl.h>

Q_LOGGING_CATEGORY(lcRestClient, "redmine.restclient")
namespace redmine {

RestClient::RestClient(QObject* parent)
    : m_Manager(new QRestAccessManager(new QNetworkAccessManager(this), this)), QObject(parent) {}

void RestClient::setBaseUrl(const QUrl& newUrl) {
    if (newUrl == m_BaseUrl) {
        return;
    }
    m_BaseUrl = newUrl;
    emit baseUrlChanged();
}

void RestClient::setApiKey(const QString& newApiKey) {
    if (newApiKey == m_ApiKey) {
        return;
    }
    m_ApiKey = newApiKey;
    emit apiKeyChanged();
}

bool RestClient::connect() {
    if (nullptr == m_Manager) {
        qWarning(lcRestClient()) << tr("No valid instance for QNetworkAccessManager, abort!");
        return false;
    }
    return true;
}

} // namespace redmine
