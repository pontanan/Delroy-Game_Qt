#include "maincharacter.h"

MainCharacter::MainCharacter() :Player(QPixmap("Resources/delroy/delroy_right.png"), QRect(400, 468, 32, 32))
{

}

int MainCharacter::getX()
{
    return position.x();
}

int MainCharacter::getY()
{
    return position.y();
}

int MainCharacter::getWidth()
{
    return position.width();
}

int MainCharacter::getHeight()
{
    return position.height();
}

int MainCharacter::getCenterX()
{
    return position.center().x();
}

int MainCharacter::getCenterY()
{
    return position.center().y();
}

int MainCharacter::getXVel()
{
    return xVel;
}

int MainCharacter::getDirection()
{
    return direction; // 0 -> Right, 1 -> Left
}

void MainCharacter::setXVelocity(float newVelocity)
{
    xVel = newVelocity;
}

void MainCharacter::setYVelocity(float newVelocity)
{
    yVel = newVelocity;
}

void MainCharacter::setDirection(int newDirection)
{
    direction = newDirection;
}

void MainCharacter::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void MainCharacter::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void MainCharacter::jump()
{
    if (isJumping == false)
    {
        yVel = -15;
        isJumping = true;
    }
}

void MainCharacter::update(Ground *ground)
{
    if (isJumping)
    {
        yVel += gravity;

         //Check direction | 0 -> Right, 1 -> Left
         if(direction == 0)
            setPosition(position.x()/* + xVel*/, position.y() + yVel);
         else
             setPosition(position.x()/* - xVel*/, position.y() + yVel);
     }
    else
    {
        yVel += gravity;
        setPosition(position.x(), position.y() + yVel);
    }

    if (position.y() + position.height() > ground->getY())
    {
        setPosition(position.x(), ground->getY() - position.height());
        isJumping = false;
    }

    if(position.x() <= 0)
        setPosition(0, position.y());
}
