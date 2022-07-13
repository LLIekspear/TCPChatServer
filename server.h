#ifndef SERVER_H
#define SERVER_H

#include <QtWidgets>
#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QPlainTextEdit>
#include <QHostAddress>
#include "serverDialog.h"
#include <QSql>
#include <QDomDocument>
#include "user.h"

class Server : public QWidget {

    Q_OBJECT

    public:
        Server();
        void sendToAll(const QString &message);

    public slots:
        void on_accept();
    private slots:
        void newConnection();
        void dataReceived();
        void logoutUser();
        void on_starting();
        void on_stopping();
        void on_saveLogs();
        void on_network();

    private:
        QMenu *fileMenu;
        QMenu *settingsMenu;
        QAction *networkAction;
        QAction *startAction;
        QAction *stopAction;
        QAction *exitAction;
        QAction *saveLogsAction;
        QTextEdit *logs;
        QLabel *serverState;
        QPushButton *quitButton;
        quint16 port=45678;
        QHostAddress ip=QHostAddress("127.0.0.1");
        QTcpServer *server;
        QList<QTcpSocket *> users;
        QMap<QTcpSocket *, User *> usersInfo;
        quint16 messageLength;
        ServerDialog *sDialog;
        QDomDocument *doc;
        QDomElement domElement;
        void userListUpdated();
        void saveXMLLogs();
        QDomElement log(QDomDocument *domDoc, const QString &dateTime, const QString &ip, const QString &name, const QString &type, const QString &message);
        QDomElement makeElement(QDomDocument *domDoc, const QString &strName, const QString &stdAttr, const QString &Text);
        QMap<QString, QList<QString>> filesList;

};

#endif // SERVER_H
