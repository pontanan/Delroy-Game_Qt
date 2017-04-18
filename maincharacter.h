#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H


#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"


class MainCharacter : public Player
{
public:
    MainCharacter();
    void setPosition(int x, int y);
    void update(MainCharacter *maincharacter);
private:
    QTimer *timer;
};

#endif // MAINCHARACTER_H
