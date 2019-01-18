/********************************************************************************
** Form generated from reading UI file 'QtSnake.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSNAKE_H
#define UI_QTSNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSnakeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSnakeClass)
    {
        if (QtSnakeClass->objectName().isEmpty())
            QtSnakeClass->setObjectName(QStringLiteral("QtSnakeClass"));
        QtSnakeClass->resize(600, 400);
        menuBar = new QMenuBar(QtSnakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtSnakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtSnakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtSnakeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtSnakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtSnakeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtSnakeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtSnakeClass->setStatusBar(statusBar);

        retranslateUi(QtSnakeClass);

        QMetaObject::connectSlotsByName(QtSnakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSnakeClass)
    {
        QtSnakeClass->setWindowTitle(QApplication::translate("QtSnakeClass", "QtSnake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtSnakeClass: public Ui_QtSnakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSNAKE_H
