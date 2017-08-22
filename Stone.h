#ifndef STONE_H
#define STONE_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Obstacles.h"

class Stone: public Obstacles
{
public:
    Stone();
    int getStartX();
    int getStartY();
    void setPosition(int x, int y);
    void collision(MainCharacter *mc, Projectile *bullet, bool *killProjectile);
    void collision(MainCharacter *mc);
    void collision(Weapon *weapon);
    void update();
private:
    QTimer *timer;
};

#endif // STONE_H
