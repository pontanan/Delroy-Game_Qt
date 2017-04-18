#include <math.h>
#include "player.h"

Player::Player(QPixmap map, QRect rect) :pixmap(map), position(rect)
{
}

void Player::paint(QPainter * qp)
{
	qp->drawPixmap(position, pixmap);
}
void Player::hitCheck()
{

	/*float xdist = position.center().x() - puck->position().center().x();
	float ydist = position.center().y() - puck->position().center().y();
	float xsqrdist = xdist*xdist;
	float ysqrdist = ydist*ydist;
	float rad1 = position.width() / 2;
	float rad2 = puck->position().width() / 2;
	float totsqrrad = (rad1 + rad2)*(rad1 + rad2);
	if ((xsqrdist + ysqrdist) > totsqrrad)
		return;  //Miss
	float distance = sqrt(xsqrdist + ysqrdist);
	float colnormalX = xdist / distance;
	float colnormalY = ydist / distance;
	float dot = puck->xvel()*colnormalX + puck->yvel()*colnormalY;
	if (dot < 0)
		return;  // Ror sig ifran varandra
	if (abs(puck->xvel()) < 1.0 && abs(puck->yvel()) < 1.0)
	{
		puck->setxvel(-colnormalX * 7);
		puck->setyvel(-colnormalY * 7);
	}
	else
	{
		puck->setxvel(-((2 * dot*colnormalX) - puck->xvel()));
		puck->setyvel(-((2 * dot*colnormalY) - puck->yvel()));
	}*/
}

