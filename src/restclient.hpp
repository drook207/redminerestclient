#ifndef RESTCLIENT_HPP
#define RESTCLIENT_HPP

#include <qhashfunctions.h>
#include <qnetworkaccessmanager.h>
#include <QNetworkAccessManager>
#include <QObject>
#include <QRestAccessManager>
#include <qstringliteral.h>
#include <qtclasshelpermacros.h>
#include <qtmetamacros.h>
#include <qtpreprocessorsupport.h>
#include <qurl.h>
#include <QUrlQuery>

#include <tl/expected.hpp>

#include "redminerestclient_global.h"
namespace redmine {

class REDMINERESTCLIENT_EXPORT RestClient : public QObject {
    Q_OBJECT
  public:
    explicit RestClient(QObject* parent = nullptr);

    void setBaseUrl(const QUrl& newUrl);
    [[nodiscard]] QUrl baseUrl() const;

    void setApiKey(const QString& newApiKey);
    [[nodiscard]] QString apiKey() const;

    bool connect();
    bool connect(const QUrl& baseUrl, const QString& apiKey);
    [[nodiscard]] bool isConnected() const;
    void setConnected(bool newConnected);
    void getIssue(quint32 issueId);
  signals:
    void baseUrlChanged();
    void apiKeyChanged();
    void connectedChanged();
    void aboutToConnect();
    void errorOccurred(const QString& e);

  private slots:
    void finished();
    static void authenticationRequired(QNetworkReply* /*reply*/, QAuthenticator* /*authenticator*/) {
        Q_UNIMPLEMENTED();
    };
    static void encrypted(QNetworkReply* /*reply*/) { Q_UNIMPLEMENTED(); };
    static void preSharedKeyAuthenticationRequired(QNetworkReply* /*reply*/,
                                                   QSslPreSharedKeyAuthenticator* /*authenticator*/) {
        Q_UNIMPLEMENTED();
    };
    static void proxyAuthenticationRequired(const QNetworkProxy& /*proxy*/, QAuthenticator* /*authenticator*/) {
        Q_UNIMPLEMENTED();
    };
    void sslErrors(QNetworkReply* reply, const QList<QSslError>& errors);

  private:
    static constexpr auto g_Authentication = "X-Redmine-API-Key";
    tl::expected<QNetworkRequest, QString> createRequest(const QString& endpoint, const QUrlQuery& query = QUrlQuery());
    bool m_connected;
    QUrl m_baseUrl;
    QString m_apiKey;
    QRestAccessManager* m_manager;
};
} // namespace redmine
#endif // RESTCLIENT_HPP
