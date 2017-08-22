#include "Box.h"

Box::Box():Obstacles(QPixmap("Resources/obstacles/box.png"), QRect(300, 436, 64, 64))
{

}

int Box::getX()
{
    return position.x();
}

int Box::getY()
{
    return position.y();
}

int Box::getWidth()
{
    return position.width();
}

int Box::getHeight()
{
    return position.height();
}

void Box::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Box::update(MainCharacter *mc, Projectile *bullet, bool *killProjectile)
{
    if( hitCheck(bullet) )
    {
        bullet->isMoving = false;
        *killProjectile = true;
    }
    if( hitCheck(mc) )
    {
        if(mc->isJumping)
            mc->isJumping = false;

        if(mc->getY() + mc->getHeight() >= position.y() &&  mc->getY() + mc->getHeight() <= position.y() + 10)
        {
            mc->setPosition(mc->getX(), position.y() - position.height());
            mc->setYVelocity(0);
        }
        else if(mc->getDirection() == 0)
            mc->setPosition(position.x() - mc->getWidth(), position.bottom() - (mc->getHeight() - 1));
        else if(mc->getDirection() == 1)
            mc->setPosition(position.x() + position.width(), position.bottom() - (mc->getHeight() - 1));
    }
}

void Box::update(MainCharacter *mc)
{
    if( hitCheck(mc) )
    {
        if(mc->isJumping)
            mc->isJumping = false;

        if(mc->getY() + mc->getHeight() >= position.y() &&  mc->getY() + mc->getHeight() <= position.y() + 10)
        {
            mc->setPosition(mc->getX(), position.y() - position.height() + 31);
            mc->setYVelocity(0);
        }
        else if(mc->getDirection() == 0)
            mc->setPosition(position.x() - mc->getWidth(), position.bottom() - (mc->getHeight() - 1));
        else if(mc->getDirection() == 1)
            mc->setPosition(position.x() + position.width(), position.bottom() - (mc->getHeight() - 1));
    }
}

