#include "Projectile.h"

Projectile::Projectile() :pixmap(QPixmap("Resources/weapons/gun_projectile.png")), position(QRect(85, 484, 2, 2))
{
}

int Projectile::getX()
{
    return position.x();
}

int Projectile::getY()
{
    return position.y();
}

int Projectile::getWidth()
{
    return position.width();
}

int Projectile::getHeight()
{
    return position.height();
}

void Projectile::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Projectile::setDirection(int newDirection)
{
    direction = newDirection;
}

void Projectile::checkCollision(bool **killProjectile)
{
    //Check if outside window
    if(position.x() <= 0 || position.x() >= 1200)
    { isMoving = false; **killProjectile = true;}
}

void Projectile::move()
{
    isMoving = true;
}

void Projectile::update(bool *killProjectile)
{
    checkCollision(&killProjectile);

    //Check if moving
    if(isMoving)
    {
        if(direction == 0)
            setPosition(position.x() + xVel, position.y());
        else
            setPosition(position.x() - xVel, position.y());
    }

}

void Projectile::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Projectile::~Projectile()
{
}
