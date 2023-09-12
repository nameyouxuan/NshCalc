#include "update.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDir>

Update::Update(QObject *parent) : QObject(parent)
{
    QFile file("../NshCalc/settings.json");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error1:" << file.errorString();
        QMessageBox::warning(nullptr, "File Error", "Failed to open settings.json");
        return;
    }

    // 读取JSON文件的全部内容
    QByteArray jsonData = file.readAll();

    // 解析JSON数据
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (doc.isNull())
    {
        qDebug() << "Error2:" << file.errorString();
        QMessageBox::warning(nullptr, "JSON Error", "Failed to parse JSON.");
        return;
    }

    if (doc.isObject())
    {
        QJsonObject jsonObj = doc.object();
        if (jsonObj.contains("version"))
        {
            currentVersion = jsonObj["version"].toString();
        }
        if (jsonObj.contains("url"))
        {
            url = jsonObj["url"].toString();
        }
    }
    qDebug() << doc.toJson(QJsonDocument::Indented);
    file.close();

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Update::onResult);
}

Update::~Update()
{
}

void Update::checkForUpdates()
{
    QNetworkRequest request(url);
    networkManager->get(request);
}

void Update::onResult(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray jsonData = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(jsonData);
        QJsonObject obj = document.object();
        QString latestVersion = obj["version"].toString();

        if (latestVersion != currentVersion)
        {
QMessageBox msgBox;
            msgBox.setWindowTitle("更新可用");
            msgBox.setText("新版本可用：" + latestVersion);
            msgBox.setInformativeText("你想现在更新吗？");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);

            if (msgBox.exec() == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl(url));
            }
        }
    }
}

