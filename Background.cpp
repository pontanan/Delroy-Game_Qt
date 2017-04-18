#include "Background.h"

Background::Background() :Player(QPixmap("Resources/background/background.png"), QRect(0, 0, 2400, 600))
{

}

void Background::setPosition(int x, int y)
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
