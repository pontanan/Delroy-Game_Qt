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

void Projectile::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Projectile::checkCollision(/*Box *box*/ bool **killProjectile)
{
    //Check if outside window
    if(position.x() <= 0 || position.x() >= 800)
    { isMoving = false; **killProjectile = true;}
}

void Projectile::move()
{
    isMoving = true;
}

void Projectile::update(bool isRight, bool *killProjectile)
{
    checkCollision(&killProjectile);

    //Check if moving
    if(isMoving)
    {
        if(isRight)
            setPosition(position.x() + 10, position.y());
        else
            setPosition(position.x() - 10, position.y());
    }

}

void Projectile::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Projectile::~Projectile()
{
}
