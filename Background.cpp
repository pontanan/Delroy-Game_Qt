#include "background.h"

Background::Background() :pixmap(QPixmap("Resources/background/background.png")), position(QRect(0, 0, 2400, 600))
{
}

int Background::getX()
{
    return position.x();
}

int Background::getY()
{
    return position.y();
}

int Background::getWidth()
{
    return position.width();
}

int Background::getHeight()
{
    return position.height();
}

void Background::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Background::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

void Background::update()
{

}

