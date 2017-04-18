#ifndef WEAPON_H
#define WEAPON_H

#include <QWidget>
#include <QPainter>

class Weapon
{
public:
    Weapon();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void checkCollision();
    void update(Weapon * weapon);
    void paint(QPainter * qp);
protected:
    QPixmap pixmap;
    QRect position;
};


#endif // WEAPON_H
