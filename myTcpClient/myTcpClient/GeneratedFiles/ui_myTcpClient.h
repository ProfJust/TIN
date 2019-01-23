/********************************************************************************
** Form generated from reading UI file 'myTcpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTCPCLIENT_H
#define UI_MYTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myTcpClientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myTcpClientClass)
    {
        if (myTcpClientClass->objectName().isEmpty())
            myTcpClientClass->setObjectName(QStringLiteral("myTcpClientClass"));
        myTcpClientClass->resize(600, 400);
        menuBar = new QMenuBar(myTcpClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        myTcpClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myTcpClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        myTcpClientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(myTcpClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myTcpClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myTcpClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myTcpClientClass->setStatusBar(statusBar);

        retranslateUi(myTcpClientClass);

        QMetaObject::connectSlotsByName(myTcpClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *myTcpClientClass)
    {
        myTcpClientClass->setWindowTitle(QApplication::translate("myTcpClientClass", "myTcpClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myTcpClientClass: public Ui_myTcpClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTCPCLIENT_H
