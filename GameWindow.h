#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtGui>
#include "Character.h"
#include "Ground.h"


namespace Ui {
	class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	void paintEvent(QPaintEvent * e);
	void mouseMoveEvent(QMouseEvent* e);

	explicit GameWindow(QWidget *parent = 0);
	~GameWindow();

private:
	Ui::GameWindow *ui;
	QTimer * timer;
		Character character;
		Ground ground;
private slots:
	void update();
};

#endif // GAMEWINDOW_H

