#include "Weapon.h"

Weapon::Weapon() :pixmap(QPixmap("Resources/weapons/gun_right.png")), position(76, 485, 7, 6)
{
}

int Weapon::getX()
{
    return position.x();
}

int Weapon::getY()
{
    return position.y();
}

int Weapon::getWidth()
{
    return position.width();
}

int Weapon::getHeight()
{
    return position.height();
}

int Weapon::getDirection()
{
    return direction;
}

void Weapon::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Weapon::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void Weapon::shoot(QVector<Projectile> *bulletVec, int mcDirection)
{
    //Create Bullet
    Projectile bullet;

    //Check direction
    if(mcDirection == 0)
        bullet.setPosition(position.right(), position.top());
    else
        bullet.setPosition(position.left(), position.top());

    bullet.setDirection(mcDirection); //Set Bullet direction to MainCharacter direction

    bulletVec->push_back(bullet); //Push in the new Bullet into the Bullet-vector
    bullet.move(); //Start moving proccess for Bullet
}

void Weapon::update(MainCharacter * maincharacter, int mcDirection)
{
    int x = position.x();
    int y = position.y();
    int mcX = maincharacter->getX();
    y = maincharacter->getCenterY();
    direction = mcDirection;

    //y = mcCenterY;

    //Check MainCharacter direction -> 0 = right, 1 = left
    if(mcDirection == 0)
    {
        x = mcX + 27;
        setPosition(x, y);
    }
    else
    {
        x = mcX - 1;
        setPosition(x, y);
    }
}

void Weapon::paint(QPainter * qp)
{
    qp->drawPixmap(position, pixmap);
}

Weapon::~Weapon()
{
}
