#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
//#include "Box.h"

class Projectile
{

public:
    Projectile();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void checkCollision(/*Box *box*/ bool **killProjectile);
    void move();
    void update(/*Box *box,*/ bool isRight, bool *killProjectile);
    void paint(QPainter * qp);
    virtual ~Projectile();

    bool isMoving;
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // PROJECTILE_H
