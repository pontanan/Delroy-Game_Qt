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
    void setSprite(QPixmap newPixmap);
    void setXVelocity(float newVelocity);
    void update();

private:
    QTimer *timer;
    float xVel;
    int direction;
};





#endif // ENEMY_H
