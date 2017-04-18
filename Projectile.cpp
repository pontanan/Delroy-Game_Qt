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

void Projectile::update(Projectile *projectile)
{

}

void Projectile::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}
