#ifndef GROUND_H
#define GROUND_H

#include <QWidget>
#include <QPainter>

class Ground
{
public:
    Ground(QPixmap map, QRect rect);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getStartX();
    int getStartY();
    void setPosition(int x, int y);
    void paint(QPainter * qp);
    void update(Ground *ground);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // GROUND_H
