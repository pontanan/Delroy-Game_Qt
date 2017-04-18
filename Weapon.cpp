#include "Weapon.h"

Weapon::Weapon() :pixmap(QPixmap("Resources/weapons/gun_right.png")), position(76, 485, 7, 6)
{
}

int Weapon::getX()
{
    return position.x();
}

int Weapon::getY()
{
    return position.y();
}

void Weapon::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Weapon::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void Weapon::shootRight(Projectile *bullet)
{
    bullet->hidden = false;
    bullet->setPosition(position.right(), position.top());
    bullet->move();
}

void Weapon::shootLeft(Projectile *bullet)
{
    bullet->hidden = false;
    bullet->setPosition(position.left(), position.top());
    bullet->move();
}

void Weapon::checkCollision()
{

}

void Weapon::update(Weapon * weapon)
{

}

void Weapon::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Weapon::~Weapon()
{
}
