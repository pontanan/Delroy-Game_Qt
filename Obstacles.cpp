#include "Obstacles.h"

Obstacles::Obstacles(QPixmap map, QRect rect) :pixmap(map), position(rect)
{

}
void Obstacles::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

int Obstacles::getX()
{
    return position.x();
}

int Obstacles::getY()
{
    return position.y();
}

int Obstacles::getHeight()
{
    return position.height();
}

int Obstacles::getWidth()
{
    return position.width();
}

bool Obstacles::hitCheck(Projectile *bullet)
{
    //Check if characters left is not colliding with the objects right
    if(bullet->getX() > position.x() + position.width())
        return false;

    //Check if characters right is not colliding with the objects left
    if(bullet->getX() + bullet->getWidth() < position.x())
        return false;

    //Check if characters top is not colliding with the objects bottom
    if(bullet->getY() > position.y() + position.height())
        return false;

    //Check if characters bottom is not colliding with the objects top
    if(bullet->getY() + bullet->getHeight() < position.y())
        return false;

    return true;
}

bool Obstacles::hitCheck(MainCharacter *mc)
{
    //Check if characters left is not colliding with the objects right
    if(mc->getX() > position.x() + position.width())
        return false;

    //Check if characters right is not colliding with the objects left
    if(mc->getX() + mc->getWidth() < position.x())
        return false;

    //Check if characters top is not colliding with the objects bottom
    if(mc->getY() > position.y() + position.height())
        return false;

    //Check if characters bottom is not colliding with the objects top
    if(mc->getY() + mc->getHeight() < position.y())
        return false;

    return true;
}

bool Obstacles::hitCheck(Weapon *weapon)
{
    //Check if characters left is not colliding with the objects right
    if(weapon->getX() > position.x() + position.width())
        return false;

    //Check if characters right is not colliding with the objects left
    if(weapon->getX() + weapon->getWidth() < position.x())
        return false;

    //Check if characters top is not colliding with the objects bottom
    if(weapon->getY() > position.y() + position.height())
        return false;

    //Check if characters bottom is not colliding with the objects top
    if(weapon->getY() + weapon->getHeight() < position.y())
        return false;

    return true;
}
