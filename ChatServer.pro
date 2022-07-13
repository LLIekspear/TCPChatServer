TEMPLATE = app

QT+=widgets network sql xml

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += \
    main.cpp \
    server.cpp \
    serverDialog.cpp \
    user.cpp

HEADERS += \
    server.h \
    serverDialog.h \
    user.h
