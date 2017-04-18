#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H


#include <QWidget>
#include <Qpainter>
#include <QKeyEvent>
#include "Player.h"

class MainCharacter : public Player
{
public:
    MainCharacter();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void setSprite(QPixmap newPixmap);
    void update(MainCharacter *maincharacter);
private:
};

#endif // MAINCHARACTER_H
