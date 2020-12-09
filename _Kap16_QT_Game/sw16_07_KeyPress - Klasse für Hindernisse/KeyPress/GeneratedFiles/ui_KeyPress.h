/********************************************************************************
** Form generated from reading UI file 'KeyPress.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPRESS_H
#define UI_KEYPRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyPressClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KeyPressClass)
    {
        if (KeyPressClass->objectName().isEmpty())
            KeyPressClass->setObjectName(QString::fromUtf8("KeyPressClass"));
        KeyPressClass->resize(600, 400);
        menuBar = new QMenuBar(KeyPressClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        KeyPressClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KeyPressClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KeyPressClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(KeyPressClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        KeyPressClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(KeyPressClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KeyPressClass->setStatusBar(statusBar);

        retranslateUi(KeyPressClass);

        QMetaObject::connectSlotsByName(KeyPressClass);
    } // setupUi

    void retranslateUi(QMainWindow *KeyPressClass)
    {
        KeyPressClass->setWindowTitle(QCoreApplication::translate("KeyPressClass", "KeyPress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyPressClass: public Ui_KeyPressClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPRESS_H
