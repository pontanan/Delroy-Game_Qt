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

void Stone::update(MainCharacter *mc)
{
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
