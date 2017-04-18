TEMPLATE = app
QT += core sql widgets gui
CONFIG += c++11


SOURCES += main.cpp \
    GameObject.cpp \
    GameWindow.cpp \
    Player.cpp

DISTFILES += \
    DelroyGm.pro.user \
    README.md

HEADERS += \
    GameObject.h \
    GameWindow.h \
    Player.h \
    Resources/ui_gamewindow.h

FORMS += \
    Resources/gamewindow.ui
