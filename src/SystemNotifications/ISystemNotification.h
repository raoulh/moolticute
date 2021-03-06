#ifndef ISYSTEMNOTIFICATION_H
#define ISYSTEMNOTIFICATION_H

#include <QObject>

class ISystemNotification : public QObject
{
    Q_OBJECT
public:
    explicit ISystemNotification(QObject *parent = nullptr): QObject(parent) {}
    virtual ~ISystemNotification() {}

    virtual void createNotification(const QString& title, const QString text) = 0;
    virtual void createButtonChoiceNotification(const QString& title, const QString text, const QStringList &buttons) = 0;
    virtual void createTextBoxNotification(const QString& title, const QString text) = 0;
    virtual bool displayLoginRequestNotification(const QString& service, QString &loginName, QString message) = 0;
    virtual bool displayDomainSelectionNotification(const QString& domain, const QString& subdomain, QString &serviceName, QString message) = 0;

signals:
    void sendLoginMessage(QString message, QString loginName);
    void sendDomainMessage(QString message, QString loginName);

};

#endif // ISYSTEMNOTIFICATION_H
