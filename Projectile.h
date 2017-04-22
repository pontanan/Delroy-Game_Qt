#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "Box.h"

class Projectile
{

public:
    Projectile();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void checkCollision(Box *box);
    void move();
    void update(Box *box, bool isRight);
    void paint(QPainter * qp);
    virtual ~Projectile();

    bool hidden = true;
protected:
    QPixmap pixmap;
    QRect position;
private:
    bool isMoving;
};

#endif // PROJECTILE_H
