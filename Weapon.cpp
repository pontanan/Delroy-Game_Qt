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

void Weapon::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(), position.height());
}

void Weapon::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}

void Weapon::shoot(QVector<Projectile> *bulletVec, bool isRight)
{
    //Create Bullet
    Projectile bullet;

    //Check direction
    if(isRight)
        bullet.setPosition(position.right(), position.top());
    else
        bullet.setPosition(position.left(), position.top());

    bulletVec->push_back(bullet);
    bullet.move();
}

void Weapon::checkCollision()
{

}

void Weapon::update(MainCharacter * maincharacter, bool isRight)
{
    int x = position.x();
    int y = position.y();
    int mcX = maincharacter->getX();
    int mcCenterY = maincharacter->getCenterY();

    y = mcCenterY;

    //Check where MainCharacter is looking
    if(isRight)
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
