#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QPainter>

class Background
{
public:
    Background();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setPosition(int x, int y);
    void paint(QPainter * qp);
    void update();
protected:
    QPixmap pixmap;
    QRect position;
};

#endif // BACKGROUND_H
