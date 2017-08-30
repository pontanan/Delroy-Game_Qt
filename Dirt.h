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
    int getStartX();
    int getStartY();
    void update();
private:
    QTimer *timer;
};

#endif // DIRT_H
