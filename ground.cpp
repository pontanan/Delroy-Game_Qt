#include <math.h>
#include "ground.h"

Ground::Ground(QPixmap map, QRect rect) :pixmap(map), position(rect)
{
}

int Ground::getX()
{
    return position.x();
}

int Ground::getY()
{
    return position.y();
}

int Ground::getWidth()
{
    return position.width();
}

int Ground::getHeight()
{
    return position.height();
}

int Ground::getStartX()
{
    return 0;
}

int Ground::getStartY()
{
    return 500;
}

void Ground::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Ground::paint(QPainter * qp)
{
     qp->drawPixmap(position, pixmap);
}

void Ground::update(Ground *ground)
{
    Ground *tempground = ground;
}
