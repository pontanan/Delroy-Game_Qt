#ifndef STONE_H
#define STONE_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Obstacles.h"
class Stone: public Obstacles
{
public:
    Stone();
    void setPosition(int x, int y);
    void update(Stone *stone);
private:
    QTimer *timer;
};

#endif // STONE_H
