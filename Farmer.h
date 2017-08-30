#ifndef FARMER_H
#define FARMER_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"

class Farmer : public Player
{
public:
    Farmer();
    void setPosition(int x, int y);
    void update();
private:
    QTimer *timer;
};

#endif // FARMER_H




