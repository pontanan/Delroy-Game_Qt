#include "Box.h"

Box::Box():Obstacles(QPixmap("Resources/obstacles/box.png"), QRect(300, 436, 64, 64))
{

}
void Box::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Box::update(Box *box)
{

}
