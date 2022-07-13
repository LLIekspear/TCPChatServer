#include <QApplication>
#include "server.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    app.setOrganizationName("Frolov Oleg SKB201");
    app.setApplicationName("TCP-Server");
    Server window;
    window.show();

    return app.exec();
}
