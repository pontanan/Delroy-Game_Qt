#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGui>
#include "Background.h"
#include "maincharacter.h"
//#include "Ground.h"


namespace Ui {
	class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	void paintEvent(QPaintEvent * e);
	void mouseMoveEvent(QMouseEvent* e);
  void keyPressEvent(QKeyEvent *e);

	explicit GameWindow(QWidget *parent = 0);
	~GameWindow();

private:
	Ui::GameWindow *ui;
	QTimer * timer;
    Background background;
    MainCharacter maincharacter;
private slots:
    void update();
};

#endif // GAMEWINDOW_H

