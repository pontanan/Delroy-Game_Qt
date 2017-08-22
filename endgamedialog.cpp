#include "endgamedialog.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndGameDialog)
{
    ui->setupUi(this);
}

EndGameDialog::~EndGameDialog()
{
    delete ui;
}

void EndGameDialog::on_buttonBox_accepted()
{
    qApp->quit();
}

void EndGameDialog::on_buttonBox_rejected()
{
    close();
}
