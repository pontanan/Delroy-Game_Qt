#include "Stone.h"

Stone::Stone():Obstacles(QPixmap("Resources/obstacles/stone.png"), QRect(200, 468, 32, 32))
{

}

void Stone::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}
