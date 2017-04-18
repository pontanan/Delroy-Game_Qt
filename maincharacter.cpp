#include "maincharacter.h"

MainCharacter::MainCharacter() :Player(QPixmap("Resources/delroy/delroy_right.png"), QRect(50, 499, 32, 32))
{

}

int MainCharacter::getX()
{
    return this->position.x();
}

int MainCharacter::getY()
{
    return this->position.y();
}

void MainCharacter::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void MainCharacter::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void MainCharacter::update(MainCharacter *maincharacter)
{

}
