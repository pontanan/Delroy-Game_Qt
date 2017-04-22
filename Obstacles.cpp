#include "Obstacles.h"

Obstacles::Obstacles(QPixmap map, QRect rect) :pixmap(map), position(rect)
{

}
void Obstacles::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}
void Obstacles::hitCheck()
{
}
