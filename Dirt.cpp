#include "Dirt.h"

Dirt::Dirt():Ground(QPixmap("Resources/ground/dirt.png"), QRect(0, 500, 500, 100))
{
}

int Dirt::getStartX()
{
    return 0;
}

int Dirt::getStartY()
{
    return 500;
}

void Dirt::update()
{

}
