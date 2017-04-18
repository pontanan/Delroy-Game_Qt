#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGui>
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
    bool shootLeft;
    bool shootRight = true;
    bool firstLeft = true;
    bool firstRight;
      Background background;
      Dirt dirt;
      MainCharacter maincharacter;
      Enemy enemy;
      Farmer farmer;
      Projectile projectile;
      Weapon weapon;
      Box box;
      Stone stone;
      Grass grass;
private slots:
    void update();
    void keyPressEvent(QKeyEvent *e);
};

#endif // GAMEWINDOW_H

