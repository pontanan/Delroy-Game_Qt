#ifndef WEAPON_H
#define WEAPON_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include "Projectile.h"
#include "maincharacter.h"

class Weapon
{
public:
    Weapon();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getDirection();
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void shoot(QVector<Projectile> *bulletVec, int mcDirection);
    void update(MainCharacter * maincharacter, int mcDirection);
    void paint(QPainter * qp);
    virtual ~Weapon();
protected:
    QPixmap pixmap;
    QRect position;

private:
    int direction = 0;
};


#endif // WEAPON_H
