#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include<stdio.h>
#include<stdlib.h>
#include <QMainWindow>
#include <QTimer>
#include <QtGui>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QThread>
#include "Background.h"
#include "ground.h"
#include "maincharacter.h"
#include "enemy.h"
#include "Farmer.h"
#include "Projectile.h"
#include "Weapon.h"
#include "Box.h"
#include "Stone.h"
#include "Dirt.h"
#include "Grass.h"

namespace Ui {
	class GameWindow;
}

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	void paintEvent(QPaintEvent * e);

	explicit GameWindow(QWidget *parent = 0);
	~GameWindow();
    void delay(unsigned int);
private:
	Ui::GameWindow *ui;
	QTimer * timer;
    QVector<Projectile> bulletVec;
    bool killProjectile = false;
      Background background;
      Dirt dirt;
      MainCharacter maincharacter;
      Enemy enemy;
      Farmer farmer;
      Weapon weapon;
      Box box;
      Stone stone;
      Grass grass;

private slots:
    void update();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

};

#endif // GAMEWINDOW_H

