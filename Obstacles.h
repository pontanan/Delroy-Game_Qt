#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QWidget>
#include <QPainter>
#include "Projectile.h"
#include "maincharacter.h"

class Obstacles
{
public:
    Obstacles(QPixmap map, QRect rect);
    void paint(QPainter * qp);
    void hitCheck(Projectile *bullet, bool **killProjectile);
    void hitCheck(MainCharacter *mc);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // OBSTACLES_H
