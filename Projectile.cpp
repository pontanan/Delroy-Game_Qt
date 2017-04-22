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

void Projectile::checkCollision()
{

}

void Projectile::update(Box *box)
{
    //Check if outside window
    if(position.x() <= 0 || position.x() >= 800)
    { isMoving = false; hidden = true; }

    //Check if has hit Box
    if(position.x() >= box->getX() && position.x() <= (box->getX() + box->getWidth()))
        if(position.y() >= box->getY() && position.y() <= (box->getY() + box->getHeight()))
        { isMoving = false; hidden = true; }


    //Check if Hidden is true
    if(hidden == true)
    {
        position = QRect(position.x(), position.y(), 0, 0);
    }
    else if(hidden == false)
    {
        position = QRect(position.x(), position.y(), 2, 2);
    }

    //Check if moving
    if(isMoving)
    {
        hidden = false;
        setPosition(position.x() + 10, position.y());
    }

}

void Projectile::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Projectile::~Projectile()
{
}

void Projectile::move()
{
    isMoving = true;
}
