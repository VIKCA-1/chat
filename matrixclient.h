#ifndef MATRIXCLIENT_H
#define MATRIXCLIENT_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

class MatrixClient : public QObject {
    Q_OBJECT
public:
    MatrixClient(QObject *parent = nullptr);
    void login(const QString& server, const QString& name, const QString& pass);
    QString Token() {
        return token;
    }
    QString Userid() {
        return userId;
    }
signals:
    void loginOk(const QString& token, const QString& uid);
private slots:
    void replydo(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    QNetworkReply* currReply;
    QString action;
    QString serverUrl;
    QString token;
    QString userId;
};

#endif
