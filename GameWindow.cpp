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

    /*if(maincharacter.getDirection() == 0)
    {
        background.setPosition(background.getX() - maincharacter.getXVel(), background.getY());
        dirt.setPosition(dirt.getX() - maincharacter.getXVel(), dirt.getY());
        grass.setPosition(grass.getX() - maincharacter.getXVel(), grass.getY());
        stone.setPosition(stone.getX() - maincharacter.getXVel(), stone.getY());
        box.setPosition(box.getX() - maincharacter.getXVel(), box.getY());
    }
    else if(maincharacter.getDirection() == 1)
    {

        if(background.getX() > -5)
            background.setPosition(0, 0);
        else
            background.setPosition(background.getX() + maincharacter.getXVel(), background.getY());

        if(dirt.getX() > dirt.getStartX() - 5)
            dirt.setPosition(dirt.getStartX(), dirt.getStartY());
        else
            dirt.setPosition(dirt.getX() + maincharacter.getXVel(), dirt.getY());

        if(grass.getX() > grass.getStartX() - 5)
            grass.setPosition(grass.getStartX(), grass.getStartY());
        else
            grass.setPosition(grass.getX() + maincharacter.getXVel(), grass.getY());

        if(stone.getX() > stone.getStartX() - 5)
            stone.setPosition(stone.getStartX(), stone.getStartY());
        else
            stone.setPosition(stone.getX() + maincharacter.getXVel(), stone.getY());

        if(box.getX() > box.getStartX() - 5)
            box.setPosition(box.getStartX(), box.getStartY());
        else
            box.setPosition(box.getX() + maincharacter.getXVel(), box.getY());
    }*/

    background.update(&background);
    dirt.update(&dirt);
    grass.update(&grass);
    stone.update();
    box.update();
    enemy.update();
    pitchfork.update();
    farmer.update(&farmer);
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
        /*maincharacter.setPosition(maincharacter.getX() - maincharacter.getXVel(), maincharacter.getY());*/
        weapon.setPosition(maincharacter.getX() - 1, maincharacter.getCenterY());

        if(background.getX() > -5)
            background.setPosition(0, 0);
        else
            background.setPosition(background.getX() + maincharacter.getXVel()+5, background.getY());

        if(dirt.getX() > dirt.getStartX() - 5)
            dirt.setPosition(dirt.getStartX(), dirt.getStartY());
        else
            dirt.setPosition(dirt.getX() + maincharacter.getXVel()+5, dirt.getY());

        if(grass.getX() > grass.getStartX() - 5)
            grass.setPosition(grass.getStartX(), grass.getStartY());
        else
            grass.setPosition(grass.getX() + maincharacter.getXVel()+5, grass.getY());

        if(stone.getX() > stone.getStartX() - 5)
            stone.setPosition(stone.getStartX(), stone.getStartY());
        else
            stone.setPosition(stone.getX() + maincharacter.getXVel()+5, stone.getY());

        if(box.getX() > box.getStartX() - 5)
            box.setPosition(box.getStartX(), box.getStartY());
        else
            box.setPosition(box.getX() + maincharacter.getXVel()+5, box.getY());

    }

    //If 'Right-arrowkey' is pressed
    if(e->key() == Qt::Key_Right)
    {
        maincharacter.setDirection(0);
        maincharacter.setXVelocity(5);

        weapon.setSprite(QPixmap("Resources/weapons/gun_right.png"));
        maincharacter.setSprite(QPixmap("Resources/delroy/delroy_right.png"));
        /*maincharacter.setPosition(maincharacter.getX() + maincharacter.getXVel(), maincharacter.getY());*/
        weapon.setPosition(maincharacter.getX() + 27, maincharacter.getCenterY());

        background.setPosition(background.getX() - maincharacter.getXVel()-5, background.getY());
        dirt.setPosition(dirt.getX() - maincharacter.getXVel()-5, dirt.getY());
        grass.setPosition(grass.getX() - maincharacter.getXVel()-5, grass.getY());
        stone.setPosition(stone.getX() - maincharacter.getXVel()-5, stone.getY());
        box.setPosition(box.getX() - maincharacter.getXVel()-5, box.getY());

        if(e->key() == Qt::Key_Space)
        {
            maincharacter.jump();
        }
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


