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
	timer->start(60);
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
    repaint();
}

void GameWindow::paintEvent(QPaintEvent * e)
{
	QPainter qp(this);
      background.paint(&qp);
      dirt.paint(&qp);
      maincharacter.paint(&qp);
}

void GameWindow::keyPressEvent(QKeyEvent * e)
{
    if(e->key() == Qt::Key_Left)
    {
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_left.png"));
        maincharacter.setPosition(maincharacter.getX() - 5, maincharacter.getY());
    }
    if(e->key() == Qt::Key_Right)
    {
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        maincharacter.setPosition(maincharacter.getX() + 5, maincharacter.getY());
    }
}


