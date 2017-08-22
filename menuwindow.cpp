#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_playBtn_clicked()
{
    GameWindow *mainWindow = new GameWindow;
    mainWindow->show();
    hide();
}

void MenuWindow::on_endBtn_clicked()
{
    close();
}
