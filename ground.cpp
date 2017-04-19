#include <math.h>
#include "ground.h"

Ground::Ground(QPixmap map, QRect rect) :pixmap(map), position(rect)
{
}

void Ground::paint(QPainter * qp)
{
     qp->drawPixmap(position, pixmap);
}

int Ground::getX()
{
    return position.x();
}

int Ground::getY()
{
    return position.y();
}

void Ground::hitCheck()
{
}

void Ground::update(Ground *ground)
{
    Ground *tempground = ground;
}
