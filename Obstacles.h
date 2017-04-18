#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QWidget>
#include <QPainter>
class Obstacles
{
public:
    Obstacles(QPixmap map, QRect rect);
    void paint(QPainter * qp);
    void hitCheck();
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // OBSTACLES_H
