#include "Enemy.h"

Enemy::Enemy() :Player(QPixmap("Resources/hen/hen_left.png"), QRect(450, 404, 96, 96))
{

}

void Enemy::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Enemy::update(Enemy *enemy)
{

}
