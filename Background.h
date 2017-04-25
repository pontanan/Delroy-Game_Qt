#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QPainter>

class Background
{
public:
    Background();
    void paint(QPainter * qp);
    void update(Background *background);
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // BACKGROUND_H
