/********************************************************************************
** Form generated from reading UI file 'sw01_qt_first_project.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SW01_QT_FIRST_PROJECT_H
#define UI_SW01_QT_FIRST_PROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sw01_qt_first_projectClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sw01_qt_first_projectClass)
    {
        if (sw01_qt_first_projectClass->objectName().isEmpty())
            sw01_qt_first_projectClass->setObjectName(QString::fromUtf8("sw01_qt_first_projectClass"));
        sw01_qt_first_projectClass->resize(600, 400);
        centralWidget = new QWidget(sw01_qt_first_projectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sw01_qt_first_projectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sw01_qt_first_projectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        sw01_qt_first_projectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sw01_qt_first_projectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sw01_qt_first_projectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sw01_qt_first_projectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sw01_qt_first_projectClass->setStatusBar(statusBar);

        retranslateUi(sw01_qt_first_projectClass);

        QMetaObject::connectSlotsByName(sw01_qt_first_projectClass);
    } // setupUi

    void retranslateUi(QMainWindow *sw01_qt_first_projectClass)
    {
        sw01_qt_first_projectClass->setWindowTitle(QCoreApplication::translate("sw01_qt_first_projectClass", "sw01_qt_first_project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sw01_qt_first_projectClass: public Ui_sw01_qt_first_projectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SW01_QT_FIRST_PROJECT_H
