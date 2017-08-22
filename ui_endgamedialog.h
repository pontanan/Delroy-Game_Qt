/********************************************************************************
** Form generated from reading UI file 'endgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEDIALOG_H
#define UI_ENDGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EndGameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *EndGameDialog)
    {
        if (EndGameDialog->objectName().isEmpty())
            EndGameDialog->setObjectName(QStringLiteral("EndGameDialog"));
        EndGameDialog->resize(304, 109);
        buttonBox = new QDialogButtonBox(EndGameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 60, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(EndGameDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 291, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(EndGameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EndGameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EndGameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EndGameDialog);
    } // setupUi

    void retranslateUi(QDialog *EndGameDialog)
    {
        EndGameDialog->setWindowTitle(QApplication::translate("EndGameDialog", "Dialog", 0));
        label->setText(QApplication::translate("EndGameDialog", "Do you really want to exit?", 0));
    } // retranslateUi

};

namespace Ui {
    class EndGameDialog: public Ui_EndGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEDIALOG_H
