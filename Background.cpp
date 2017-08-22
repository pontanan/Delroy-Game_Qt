#include "background.h"

Background::Background() :pixmap(QPixmap("Resources/background/background.png")), position(QRect(0, 0, 2400, 600))
{
}

void Background::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

void Background::update(Background *background)
{

}
