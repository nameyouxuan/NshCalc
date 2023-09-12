#ifndef UPDATE_H
#define UPDATE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Update : public QObject
{
    Q_OBJECT

public:
    explicit Update(QObject *parent = nullptr);
    ~Update();
    void checkForUpdates();

private slots:
    void onResult(QNetworkReply *reply);

private:
    QString currentVersion;
    QString url;
    QNetworkAccessManager *networkManager;
};

#endif // UPDATE_H
