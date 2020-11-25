/********************************************************************************
** Form generated from reading UI file '_FirstDrawEui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__FIRSTDRAWEUI_H
#define UI__FIRSTDRAWEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__FirstDrawClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *_FirstDrawClass)
    {
        if (_FirstDrawClass->objectName().isEmpty())
            _FirstDrawClass->setObjectName(QString::fromUtf8("_FirstDrawClass"));
        _FirstDrawClass->resize(600, 400);
        menuBar = new QMenuBar(_FirstDrawClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        _FirstDrawClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(_FirstDrawClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        _FirstDrawClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(_FirstDrawClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        _FirstDrawClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(_FirstDrawClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        _FirstDrawClass->setStatusBar(statusBar);

        retranslateUi(_FirstDrawClass);

        QMetaObject::connectSlotsByName(_FirstDrawClass);
    } // setupUi

    void retranslateUi(QMainWindow *_FirstDrawClass)
    {
        _FirstDrawClass->setWindowTitle(QApplication::translate("_FirstDrawClass", "_FirstDraw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _FirstDrawClass: public Ui__FirstDrawClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__FIRSTDRAWEUI_H
