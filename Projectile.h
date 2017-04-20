#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "Box.h"

class Projectile : public QObject
{
    Q_OBJECT

public:
    Projectile();
    int getX();
    int getY();
    void setPosition(int x, int y);
    void checkCollision();
    void update(Projectile * projectile, Box *box);
    void paint(QPainter * qp);
    virtual ~Projectile();

    bool hidden = true;
public slots:
    void move();
protected:
    QPixmap pixmap;
    QRect position;
private:
    QTimer *timer;
};

#endif // PROJECTILE_H
