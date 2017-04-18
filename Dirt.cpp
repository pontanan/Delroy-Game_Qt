#include "Dirt.h"

Dirt::Dirt():Ground(QPixmap("Resources/ground/dirt.png"), QRect(0, 500, 500, 100))
{
}
void Dirt::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Dirt::update(Dirt *dirt)
{

}
