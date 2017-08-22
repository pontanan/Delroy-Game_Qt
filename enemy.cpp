#include "Enemy.h"

Enemy::Enemy() :Player(QPixmap("Resources/hen/hen_left.png"), QRect(450, 404, 96, 96)),direction(1.0)
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

void Enemy::update(Enemy *enemy)
{

    float x=0;
    x = position.x()+direction;
    if (x < 600)
       direction = -direction;
       // enemy->setSprite(QPixmap("Resources/hen/left.png"));
    if (x > 300)
    {direction = -direction;
       // enemy->setSprite(QPixmap("Resources/hen/right.png"));
    }
    position = QRect(x, position.y(), position.width(), position.height());




}

void Enemy::setXVelocity(float newVelocity)
{
    xVel = newVelocity;
}


