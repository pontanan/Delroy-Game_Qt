#include "Grass.h"

Grass::Grass():Ground(QPixmap("Resources/ground/grass.png"), QRect(500, 500, 2400, 100))
{

}
void Grass::setPosition(int x, int y)
{
    position = QRect(x, y, position.width(),position.height());
}

void Grass::update(Grass *grass)
{

}
