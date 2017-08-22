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

void Box::collision(MainCharacter *mc, Projectile *bullet, bool *killProjectile)
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

        if(mc->getDirection() == 0)
            mc->setPosition(position.x() - mc->getWidth(), position.bottom() - (mc->getHeight() - 1));
        else
            mc->setPosition(position.x() + position.width(), position.bottom() - (mc->getHeight() - 1));
    }
}

void Box::collision(MainCharacter *mc)
{
    if( hitCheck(mc) )
    {
        if(mc->isJumping)
            mc->isJumping = false;

        if(mc->getDirection() == 0)
            mc->setPosition(position.x() - mc->getWidth(), position.bottom() - (mc->getHeight() - 1));
        else
            mc->setPosition(position.x() + position.width(), position.bottom() - (mc->getHeight() - 1));
    }
}

void Box::update()
{

}
