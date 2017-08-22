#ifndef PITCHFORK_H
#define PITCHFORK_H

#endif // PITCHFORK_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"

class Pitchfork : public Player
{
public:
    Pitchfork();
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void setXVelocity(float newVelocity);
    void update();

private:
    QTimer *timer;
    float xVel;
    float yVel;
};
