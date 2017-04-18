#ifndef GRASS_H
#define GRASS_H

#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "ground.h"
class Grass : public Ground
{
public:
    Grass();
    void setPosition(int x, int y);
    void update(Grass *grass);
private:
    QTimer *timer;
};

#endif // GRASS_H
