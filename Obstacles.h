#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include "Projectile.h"
#include "maincharacter.h"
#include "Weapon.h"

class Obstacles
{
public:
    Obstacles(QPixmap map, QRect rect);
    void paint(QPainter * qp);
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    bool hitCheck(Projectile *bullet);
    bool hitCheck(MainCharacter *mc);
    bool hitCheck(Weapon *weapon);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // OBSTACLES_H
