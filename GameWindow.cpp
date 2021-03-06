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
    background.update();
    dirt.update();
    grass.update();
    stone.update();
    box.update();
    enemy.update();
    pitchfork.update();
    farmer.update();
    maincharacter.update(&dirt);
    weapon.update(&maincharacter, maincharacter.getDirection());


    //--------------------Collision Control-----------------------//
    if(bulletVec.size() > 0)
    {
        for(int i = 0; i < bulletVec.size();i++)
        {
            stone.collision(&maincharacter, &bulletVec[i], &killProjectile);
            box.collision(&maincharacter, &bulletVec[i], &killProjectile);
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
        stone.collision(&maincharacter);
        stone.collision(&weapon);
        box.collision(&maincharacter);
        box.collision(&weapon);
    }

    repaint();
}

void GameWindow::paintEvent(QPaintEvent * e)
{
    QPainter qp(this);
    background.paint(&qp);
    dirt.paint(&qp);
    enemy.paint(&qp);
    pitchfork.paint(&qp);
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
        maincharacter.setDirection(1); //0 = right, 1 = left
        maincharacter.setXVelocity(5);


        weapon.setSprite(QPixmap("Resources/weapons/gun_left.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_left.png"));
        maincharacter.setPosition(maincharacter.getX() - maincharacter.getXVel(), maincharacter.getY());
        weapon.setPosition(maincharacter.getX() - 1, maincharacter.getCenterY());

    }

    //If 'Right-arrowkey' is pressed
    if(e->key() == Qt::Key_Right)
    {
        maincharacter.setDirection(0);
        maincharacter.setXVelocity(5);

        weapon.setSprite(QPixmap("Resources/weapons/gun_right.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        maincharacter.setPosition(maincharacter.getX() + maincharacter.getXVel(), maincharacter.getY());
        weapon.setPosition(maincharacter.getX() + 27, maincharacter.getCenterY());

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

    if(e->key() == Qt::Key_Escape)
    {
        close();
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


