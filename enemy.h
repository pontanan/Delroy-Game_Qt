#ifndef ENEMY_H
#define ENEMY_H


#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"

class Enemy : public Player
{
public:
    Enemy();
    void setPosition(int x, int y);
    void update(Enemy *enemy);
    void setXVelocity(float newVelocity);
    void setSprite(QPixmap newPixmap);

private:
    QTimer *timer;
    float xVel = 0;
    float direction;
};





#endif // ENEMY_H
