#ifndef GROUND_H
#define GROUND_H

#include <QWidget>
#include <QPainter>

class Ground
{
public:
    Ground();
    void paint(QPainter * qp);
    void hitCheck();
    void update(Ground *ground);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // GROUND_H
