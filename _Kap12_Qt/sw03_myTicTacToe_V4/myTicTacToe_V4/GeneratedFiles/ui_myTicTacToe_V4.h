/********************************************************************************
** Form generated from reading UI file 'myTicTacToe_V4.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTICTACTOE_V4_H
#define UI_MYTICTACTOE_V4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myTicTacToe_V4Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myTicTacToe_V4Class)
    {
        if (myTicTacToe_V4Class->objectName().isEmpty())
            myTicTacToe_V4Class->setObjectName(QString::fromUtf8("myTicTacToe_V4Class"));
        myTicTacToe_V4Class->resize(600, 400);
        menuBar = new QMenuBar(myTicTacToe_V4Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        myTicTacToe_V4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myTicTacToe_V4Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        myTicTacToe_V4Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(myTicTacToe_V4Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        myTicTacToe_V4Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myTicTacToe_V4Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        myTicTacToe_V4Class->setStatusBar(statusBar);

        retranslateUi(myTicTacToe_V4Class);

        QMetaObject::connectSlotsByName(myTicTacToe_V4Class);
    } // setupUi

    void retranslateUi(QMainWindow *myTicTacToe_V4Class)
    {
        myTicTacToe_V4Class->setWindowTitle(QCoreApplication::translate("myTicTacToe_V4Class", "myTicTacToe_V4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myTicTacToe_V4Class: public Ui_myTicTacToe_V4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTICTACTOE_V4_H
