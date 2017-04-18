#ifndef ENEMY_H
#define ENEMY_H


#include <QWidget>
#include <Qpainter>
#include <QTimer>
#include "Player.h"

class Enemy : public Player
{
public:
    Enemy();
    void setPosition(int x, int y);
    void update(Enemy *enemy);
private:
    QTimer *timer;
};





#endif // ENEMY_H
