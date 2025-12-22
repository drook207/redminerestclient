#ifndef RESTCLIENT_HPP
#define RESTCLIENT_HPP

#include <qhashfunctions.h>
#include <qnetworkaccessmanager.h>
#include <QNetworkAccessManager>
#include <QObject>
#include <QRestAccessManager>
#include <qtclasshelpermacros.h>
#include <qtmetamacros.h>
#include <qtpreprocessorsupport.h>
#include <qurl.h>

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
  signals:
    void baseUrlChanged();
    void apiKeyChanged();

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
    QUrl m_BaseUrl;
    QString m_ApiKey;
    QRestAccessManager* m_Manager;
};
} // namespace redmine
#endif // RESTCLIENT_HPP
