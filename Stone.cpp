#include "Stone.h"

Stone::Stone():Obstacles(QPixmap("Resources/obstacles/stone.png"), QRect(200, 468, 32, 32))
{

}

void Stone::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Stone::update(MainCharacter *mc, Projectile *bullet, bool *killProjectile)
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

void Stone::update(MainCharacter *mc)
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
