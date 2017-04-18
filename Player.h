#ifndef SPELARE_H
#define SPELARE_H

#include <QWidget>
#include <QPainter>
#include "GameObject.h"

class Player
{
public:
	Player(QPixmap map, QRect rect);
	void paint(QPainter * qp);
	void hitCheck();
protected:
	QPixmap pixmap;
	QRect position;
};

#endif // SPELARE_H