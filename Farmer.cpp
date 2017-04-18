#include "Farmer.h"

Farmer::Farmer() :Player(QPixmap("Resources/farmer/farmer_leg.png"), QRect(600, 0, 200, 500))
{

}
void Farmer::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}
/*void Background::update(Background *background)
{
    for(int i =0; i <10; i++)
    {
        setPosition(i, 0);
    }
}*/
