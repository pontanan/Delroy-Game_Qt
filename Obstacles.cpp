#include "Obstacles.h"

Obstacles::Obstacles(QPixmap map, QRect rect) :pixmap(map), position(rect)
{

}
void Obstacles::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

void Obstacles::hitCheck(Projectile *bullet, bool **killProjectile)
{
    if(bullet->getX() >= position.x() && bullet->getX() <= (position.x() + position.width()))
        if(bullet->getY() >= position.y() && bullet->getY() <= (position.y() + position.height()))
        { bullet->isMoving = false; **killProjectile = true; }
}

void Obstacles::hitCheck(MainCharacter *mc)
{
    //Check if character is inside objects X
    if(mc->getX() + mc->getWidth() >= position.x() && mc->getX() + mc->getWidth() <= (position.x() + position.width()))
    {
        //Check if character is inside objects Y
        if(mc->getY() >= position.y() && mc->getY() <= (position.y() + position.height()))
        {
            if(mc->isJumping)
                mc->isJumping = false;
            mc->setPosition(mc->getX() - (mc->getX() + mc->getWidth() - position.x()), position.bottom() - (mc->getHeight() - 1));
        }
    }
}
