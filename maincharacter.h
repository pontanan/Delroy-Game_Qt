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
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void jump();
    void animate(bool isRight);
    void update(Ground *ground);
private:
    float yVel = 0;
    float gravity = 1.4;
    bool isJumping;

};

#endif // MAINCHARACTER_H
