#include "Farmer.h"

Farmer::Farmer() :Player(QPixmap("Resources/farmer/farmer_leg.png"), QRect(600, 0, 200, 500))
{

}
void Farmer::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}
void Farmer::update()
{

}
