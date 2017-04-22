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
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void shootRight(QVector<Projectile> *bulletVec);
    void shootLeft(QVector<Projectile> *bulletVec);
    void checkCollision();
    void update(MainCharacter * maincharacter, bool isRight);
    void paint(QPainter * qp);
    virtual ~Weapon();
protected:
    QPixmap pixmap;
    QRect position;
};


#endif // WEAPON_H
