#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QWidget>
#include <QPainter>

class Projectile
{
public:
    Projectile();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void checkCollision();
    void update(Projectile * projectile);
    void paint(QPainter * qp);
protected:
    QPixmap pixmap;
    QRect position;
    bool hidden;
};

#endif // PROJECTILE_H
