#include "Enemy.h"

Enemy::Enemy() :Player(QPixmap("Resources/hen/hen_right.png"), QRect(400, 412, 84, 88)), xVel(1.0)
{

}

void Enemy::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}


void Enemy::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void Enemy::setXVelocity(float newVelocity)
{
    xVel = newVelocity;
}

void Enemy::update()
{

    float x=0;
    x = position.x()+xVel;

    if (x < 232)
    {
       xVel = -xVel;
       setSprite(QPixmap("Resources/hen/hen_right.png"));
    }
    if (x > 452)
    {
       xVel = -xVel;
       setSprite(QPixmap("Resources/hen/hen_left.png"));
    }

    setPosition(x, position.y());

}
