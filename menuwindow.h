#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "GameWindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;

private slots:
    void on_playBtn_clicked();
    void on_endBtn_clicked();
};

#endif // MENUWINDOW_H
