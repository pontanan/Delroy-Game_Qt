#include "Grass.h"

Grass::Grass():Ground(QPixmap("Resources/ground/grass.png"), QRect(200, 500, 2400, 100))
{

}

int Grass::getStartX()
{
    return 500;
}

int Grass::getStartY()
{
    return 500;
}

void Grass::update()
{

}
