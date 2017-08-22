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
    int getWidth();
    int getHeight();
    void setPosition(int x, int y);
    void setDirection(int newDirection);
    void checkCollision(bool **killProjectile);
    void move();
    void update(bool *killProjectile);
    void paint(QPainter * qp);
    virtual ~Projectile();

    bool isMoving;
protected:
    QPixmap pixmap;
    QRect position;
private:
    float xVel = 10;
    int direction = 0;
};

#endif // PROJECTILE_H
