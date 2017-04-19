#ifndef GROUND_H
#define GROUND_H

#include <QWidget>
#include <QPainter>

class Ground
{
public:
    Ground(QPixmap map, QRect rect);
    void paint(QPainter * qp);
    int getX();
    int getY();
    void hitCheck();
    void update(Ground *ground);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // GROUND_H
