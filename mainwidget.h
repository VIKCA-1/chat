#include "matrixclient.h"

MatrixClient::MatrixClient(QObject *parent) : QObject(parent)
{
    nam = new QNetworkAccessManager(this);
    currReply = nullptr;
    connect(nam, &QNetworkAccessManager::finished, this, &MatrixClient::replydo);
}

void MatrixClient::login(const QString& server, const QString& name, const QString& pass)
{
    action = "login";
    serverUrl = server;
    QUrl url(serverUrl + "/_matrix/client/v3/login");
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["type"] = "m.login.password";
    json["user"] = name;
    json["password"] = pass;

    QByteArray data = QJsonDocument(json).toJson();
    currReply = nam->post(req, data);
}

void MatrixClient::replydo(QNetworkReply* reply)
{
    if (reply != currReply) {
        reply->deleteLater();
        return;
    }
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    if (action == "login") {
        token = json["access_token"].toString();
        userId = json["user_id"].toString();
        emit loginOk(token, userId);
    }

    currReply = nullptr;
    reply->deleteLater();
}
