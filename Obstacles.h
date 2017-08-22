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
    bool hitCheck(Projectile *bullet);
    bool hitCheck(MainCharacter *mc);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // OBSTACLES_H
