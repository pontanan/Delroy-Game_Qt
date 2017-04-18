#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"


class Background : public Player
{
public:
    Background();
    void setPosition(int x, int y);
    void update(Background *background);
private:
    QTimer *timer;
};

#endif // BACKGROUND_H
