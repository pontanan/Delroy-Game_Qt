#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H


#include <QWidget>
#include <Qpainter>
#include <QKeyEvent>
#include "Player.h"
#include "ground.h"

class MainCharacter : public Player
{
public:
    MainCharacter();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getCenterX();
    int getCenterY();
    int getXVel();
    int getDirection();
    void setXVelocity(float newVelocity);
    void setDirection(int newDirection);
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void jump();
    void animate(bool isRight);
    void update(Ground *ground);

    bool isJumping;
private:
    float yVel = 0;
    float xVel = 0;
    float gravity = 1.4;
    int direction = 0; //0 -> Right, 1 -> Left
};

#endif // MAINCHARACTER_H
