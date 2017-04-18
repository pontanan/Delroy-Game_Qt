#include <math.h>
#include "ground.h"

Ground::Ground() :pixmap(QPixmap("Resources/ground/dirt.png")), position(QRect(0, 500, 2400, 100))
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

