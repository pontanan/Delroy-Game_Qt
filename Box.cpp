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

void Box::update(Box *box)
{

}
