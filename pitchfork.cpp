#include "Pitchfork.h"

Pitchfork::Pitchfork() :Player(QPixmap("Resources/weapons/pitchfork.png"), QRect(600, 0, 137, 500)), xVel(2.0) , yVel(10.0)
{

}

void Pitchfork::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}


void Pitchfork::setSprite(QPixmap newPixmap)
{
    pixmap = newPixmap;
}


void Pitchfork::setXVelocity(float newVelocity)
{
    xVel = newVelocity;
}

void Pitchfork::update()
{

    float x = 0;
    float y = 0;
    x = position.x() + xVel;
    y = position.y() + yVel;

    if (x < 200)
    {
       xVel = -xVel;
    }
    if (x > 600)
    {
       xVel = -xVel;
    }
    if (y < -600)
    {
       yVel = -yVel;
    }
    if (y > 0)
    {
       yVel = -yVel;
    }

    setPosition(x, y);

}
