/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QPushButton *playBtn;
    QPushButton *endBtn;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(601, 642);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        playBtn = new QPushButton(centralwidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(10, 380, 161, 81));
        endBtn = new QPushButton(centralwidget);
        endBtn->setObjectName(QStringLiteral("endBtn"));
        endBtn->setGeometry(QRect(420, 380, 161, 81));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 601, 601));
        label->setPixmap(QPixmap(QString::fromUtf8("Resources/DSplash.png")));
        MenuWindow->setCentralWidget(centralwidget);
        label->raise();
        endBtn->raise();
        playBtn->raise();
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 601, 20));
        MenuWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MenuWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MenuWindow->setStatusBar(statusbar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MainWindow", 0));
        playBtn->setText(QApplication::translate("MenuWindow", "Play Game", 0));
        endBtn->setText(QApplication::translate("MenuWindow", "Exit Game", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
