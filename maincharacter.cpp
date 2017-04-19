#include "maincharacter.h"

MainCharacter::MainCharacter() :Player(QPixmap("Resources/delroy/delroy_right.png"), QRect(50, 468, 32, 32))
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
         setPosition(position.x(), position.y() + yVel);
             if (position.y() > ground->getY())
             {
                 setPosition(position.x(), ground->getY() - position.height());
                 yVel = 0;
                 isJumping = false;
             }
     }
}
