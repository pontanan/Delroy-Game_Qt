TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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
    Player.h
