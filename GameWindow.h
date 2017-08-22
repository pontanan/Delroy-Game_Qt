#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGui>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
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
#include "endgamedialog.h"
#include "pitchfork.h"

namespace Ui {
	class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	void paintEvent(QPaintEvent * e);

	explicit GameWindow(QWidget *parent = 0);
	~GameWindow();

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
      Pitchfork pitchfork;

private slots:
    void update();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // GAMEWINDOW_H

