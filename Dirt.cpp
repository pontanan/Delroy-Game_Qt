#include "Dirt.h"

Dirt::Dirt():Ground(QPixmap("Resources/ground/dirt.png"), QRect(0, 500, 200, 100))
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

void Dirt::update(Dirt *dirt)
{

}
