#include "gamewindow.h"
#include "ui_gamewindow.h"

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
    maincharacter.update(&dirt);
    weapon.update(&maincharacter, wRight);
    grass.update(&grass);
    enemy.update(&enemy);
    farmer.update(&farmer);
    box.update(&box);
    stone.update(&stone);

    if(bulletVec.size() > 0)
    {
        for(int i = 0; i < bulletVec.size();i++)
        {
            bulletVec[i].update(&box);
        }
    }

    repaint();
}

void GameWindow::paintEvent(QPaintEvent * e)
{
	QPainter qp(this);
      background.paint(&qp);
      dirt.paint(&qp);
      maincharacter.paint(&qp);
      enemy.paint(&qp);
      farmer.paint(&qp);
      weapon.paint(&qp);
      box.paint(&qp);
      stone.paint(&qp);
      grass.paint(&qp);

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
        wRight = false; //Check if looking left

        weapon.setSprite(QPixmap("Resources/weapons/gun_left.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_left.png"));
        maincharacter.setPosition(maincharacter.getX() - 5, maincharacter.getY());
        weapon.setPosition(weapon.getX() - 5, weapon.getY());

    }

    //If 'Right-arrowkey' is pressed
    if(e->key() == Qt::Key_Right)
    {
        wRight = true; //Check if looking right

        weapon.setSprite(QPixmap("Resources/weapons/gun_right.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        maincharacter.setPosition(maincharacter.getX() + 5, maincharacter.getY());
        weapon.setPosition(weapon.getX() + 5, weapon.getY());

    }


    //If 'X' is pressed
    if(e->key() == Qt::Key_X)
    {
        weapon.shootRight(&bulletVec);
    }


    //If 'Space' is pressed
    if(e->key() == Qt::Key_Space)
    {
        maincharacter.jump();
    }
}


