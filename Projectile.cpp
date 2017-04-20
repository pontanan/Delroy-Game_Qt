#include "Projectile.h"

Projectile::Projectile() :pixmap(QPixmap("Resources/weapons/gun_projectile.png")), position(QRect(85, 484, 2, 2))
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

int Projectile::getX()
{
    return position.x();
}

int Projectile::getY()
{
    return position.y();
}

void Projectile::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Projectile::checkCollision()
{

}

void Projectile::update(Projectile *projectile, Box *box)
{
    if(position.x() <= 0 || position.x() >= 800)
        projectile->hidden = true;

    if(position.x() >= box->getX() && position.x() <= (box->getX() + box->getWidth()))
        if(position.y() >= box->getY() && position.y() <= (box->getY() + box->getHeight()))
            projectile->hidden = true;

    if(hidden == true)
    {
        position = QRect(position.x(), position.y(), 0, 0);
    }
    else if(hidden == false)
    {
        position = QRect(position.x(), position.y(), 2, 2);
    }

}

void Projectile::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Projectile::~Projectile()
{
}

void Projectile::move()
{
    setPosition(position.x() + 10, position.y());
}
