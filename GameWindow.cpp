#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "QPainter"
#include <QKeyEvent>

GameWindow::GameWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GameWindow)

{
	ui->setupUi(this);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(60);
}

GameWindow::~GameWindow()
{
	delete ui;
}

void GameWindow::update()
{
    //background.update(&background);
    dirt.update(&dirt);
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
}
void GameWindow::mouseMoveEvent(QMouseEvent* e)
{

}

void GameWindow::keyPressEvent(QKeyEvent * e)
{

}
