#ifndef RESTCLIENT_HPP
#define RESTCLIENT_HPP

#include <qhashfunctions.h>
#include <QNetworkAccessManager>
#include <QObject>
#include <qtclasshelpermacros.h>

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

  private:
    QUrl m_BaseUrl;
    QString m_ApiKey;
    QNetworkAccessManager* m_Manager;
};
} // namespace redmine
#endif // RESTCLIENT_HPP
