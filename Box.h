#ifndef BOX_H
#define BOX_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Obstacles.h"
class Box: public Obstacles
{
public:
    Box();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setPosition(int x, int y);
    void update(MainCharacter *mc, Projectile *bullet, bool *killProjectile);
    void update(MainCharacter *mc);
private:
    QTimer *timer;
};

#endif // BOX_H


