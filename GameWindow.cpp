#include "gamewindow.h"
#include "ui_gamewindow.h"

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
	character.update(&character);
	ground.update(&ground);
	repaint();
}

void GameWindow::paintEvent(QPaintEvent * e)
{
	QPainter qp(this);
	character.paint(&qp);
	ground.paint(&qp);

}
void GameWindow::mouseMoveEvent(QMouseEvent* e)
{
}

