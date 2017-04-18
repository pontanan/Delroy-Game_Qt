#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "QPainter"
#include <QKeyEvent>
#include <QGraphicsItem>

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
    maincharacter.update(&maincharacter);
    projectile.update(&projectile);
    weapon.update(&weapon);
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
      projectile.paint(&qp);
      weapon.paint(&qp);
}

void GameWindow::keyPressEvent(QKeyEvent * e)
{
    if(e->key() == Qt::Key_Left)
    {
        weapon.setSprite(QPixmap("Resources/weapons/gun_left.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_left.png"));
        maincharacter.setPosition(maincharacter.getX() - 5, maincharacter.getY());
        weapon.setPosition(weapon.getX() - 5, weapon.getY());
    }
    if(e->key() == Qt::Key_Right)
    {
        weapon.setSprite(QPixmap("Resources/weapons/gun_right.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        maincharacter.setPosition(maincharacter.getX() + 5, maincharacter.getY());
        weapon.setPosition(weapon.getX() + 5, weapon.getY());
    }
}


