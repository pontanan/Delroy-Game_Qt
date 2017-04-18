#include "maincharacter.h"

MainCharacter::MainCharacter() :Player(QPixmap("Resources/delroy/delroy_right.png"), QRect(50, 499, 32, 32))
{

}

void MainCharacter::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}
/*void Background::update(Background *background)
{
    for(int i =0; i <10; i++)
    {
        setPosition(i, 0);
    }
}*/
