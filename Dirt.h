#ifndef DIRT_H
#define DIRT_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "ground.h"
class Dirt : public Ground
{
public:
    Dirt();
    void setPosition(int x, int y);
    void update(Dirt *dirt);
private:
    QTimer *timer;
};

#endif // DIRT_H
