#include <math.h>
#include "ground.h"

Ground::Ground(QPixmap map, QRect rect) :pixmap(map), position(rect)
{
}

void Ground::paint(QPainter * qp)
{
     qp->drawPixmap(position, pixmap);
}

void Ground::hitCheck()
{
}

void Ground::update(Ground *ground)
{

}
