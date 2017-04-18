TEMPLATE = app
QT += core sql widgets gui
CONFIG += c++11


SOURCES += main.cpp \
    GameObject.cpp \
    GameWindow.cpp \
    Player.cpp \
    Background.cpp \
    MainCharacter.cpp

DISTFILES += \
    DelroyGm.pro.user \
    README.md \
    Resources/background/background.png \
    Resources/delroy/delroy_left.png \
    Resources/delroy/delroy_left_walk1.png \
    Resources/delroy/delroy_left_walk2.png \
    Resources/delroy/delroy_right.png \
    Resources/delroy/delroy_right_walk1.png \
    Resources/delroy/delroy_right_walk2.png \
    Resources/farmer/farmer_leg.png \
    Resources/ground/dirt.png \
    Resources/ground/grass.png \
    Resources/hen/hen_left.png \
    Resources/hen/hen_left_walk1.png \
    Resources/hen/hen_left_walk2.png \
    Resources/hen/hen_right.png \
    Resources/hen/hen_right_walk1.png \
    Resources/hen/hen_right_walk2.png \
    Resources/obstacles/box.png \
    Resources/obstacles/stone.png \
    Resources/weapons/gun_projectile.png \
    Resources/weapons/pitchfork.png

HEADERS += \
    GameObject.h \
    GameWindow.h \
    Player.h \
    Resources/ui_gamewindow.h \
    Background.h \
    MainCharacter.h

FORMS += \
    Resources/gamewindow.ui
