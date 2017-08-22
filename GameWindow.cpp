#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <cstdlib>
GameWindow::GameWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GameWindow)

{
	ui->setupUi(this);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
    setFocusPolicy(Qt::StrongFocus);
}

GameWindow::~GameWindow()
{
	delete ui;
}

void GameWindow::update()
{
    background.update(&background);
    dirt.update(&dirt);
    grass.update(&grass);
    enemy.update(&enemy);
    farmer.update(&farmer);
    maincharacter.update(&dirt);
    weapon.update(&maincharacter, maincharacter.getDirection());






    if(bulletVec.size() > 0)
    {
        for(int i = 0; i < bulletVec.size();i++)
        {
            stone.update(&maincharacter, &bulletVec[i], &killProjectile);
            box.update(&maincharacter, &bulletVec[i], &killProjectile);
            bulletVec[i].update(&killProjectile);

            if(killProjectile)
            {
                bulletVec.erase(bulletVec.begin() + i);
                killProjectile = false;
                qDebug() << "Bullet " << i << " Killed";
            }
        }
    }
    else
    {
        stone.update(&maincharacter);
        box.update(&maincharacter);
    }

    repaint();
}

void GameWindow::paintEvent(QPaintEvent * e)
{
	QPainter qp(this);
      background.paint(&qp);
      dirt.paint(&qp);
      enemy.paint(&qp);
      farmer.paint(&qp);
      box.paint(&qp);
      stone.paint(&qp);
      grass.paint(&qp);
      maincharacter.paint(&qp);
      weapon.paint(&qp);

      if(bulletVec.size() > 0)
      {
          for(int i = 0; i < bulletVec.size();i++)
          {
              bulletVec[i].paint(&qp);
          }
      }
}

void GameWindow::keyPressEvent(QKeyEvent * e)
{

    //If 'Left-arrowkey' is pressed
    if(e->key() == Qt::Key_Left)
    {
        maincharacter.setDirection(1);
        maincharacter.setXVelocity(5);


        weapon.setSprite(QPixmap("Resources/weapons/gun_left.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_left.png"));
        maincharacter.setPosition(maincharacter.getX() - maincharacter.getXVel(), maincharacter.getY());
        weapon.setPosition(weapon.getX(), weapon.getY());

    }

    //If 'Right-arrowkey' is pressed
    if(e->key() == Qt::Key_Right)
    {
        maincharacter.setDirection(0);
        maincharacter.setXVelocity(5);

        weapon.setSprite(QPixmap("Resources/weapons/gun_right.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        maincharacter.setPosition(maincharacter.getX() + maincharacter.getXVel(), maincharacter.getY());
        weapon.setPosition(weapon.getX(), weapon.getY());

    }


    //If 'X' is pressed
    if(e->key() == Qt::Key_X)
    {
        weapon.shoot(&bulletVec, maincharacter.getDirection());
    }


    //If 'Space' is pressed
    if(e->key() == Qt::Key_Space)
    {
        maincharacter.jump();
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Right)
    {
        maincharacter.setXVelocity(0);
    }

    if(e->key() == Qt::Key_Left)
    {
        maincharacter.setXVelocity(0);
    }
}


