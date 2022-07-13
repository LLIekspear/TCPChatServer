#ifndef USER_H
#define USER_H

#include <QByteArray>
#include <QVector>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include <QIcon>
#include <QDateTime>

class User {
public:
    User();
    QString username="Test";
    QTcpSocket user_socket;
    QString status="Доступен";
    QImage icon;
    QString ip="127.0.0.1";
    bool autoFileGet=0;
    QByteArray icon_64;
    QDateTime connected_time;

private:
    QByteArray user_id;

public:
    void set_user_id(QByteArray);
    void set_username(QString);
    void set_icon(QImage);
    QByteArray get_user_id();
    QString get_username();
};
#endif // USER_H
