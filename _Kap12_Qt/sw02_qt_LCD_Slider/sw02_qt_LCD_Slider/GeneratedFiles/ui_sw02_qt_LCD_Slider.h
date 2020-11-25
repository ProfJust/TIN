/********************************************************************************
** Form generated from reading UI file 'sw02_qt_LCD_Slider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SW02_QT_LCD_SLIDER_H
#define UI_SW02_QT_LCD_SLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sw02_qt_LCD_SliderClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sw02_qt_LCD_SliderClass)
    {
        if (sw02_qt_LCD_SliderClass->objectName().isEmpty())
            sw02_qt_LCD_SliderClass->setObjectName(QString::fromUtf8("sw02_qt_LCD_SliderClass"));
        sw02_qt_LCD_SliderClass->resize(600, 400);
        menuBar = new QMenuBar(sw02_qt_LCD_SliderClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        sw02_qt_LCD_SliderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sw02_qt_LCD_SliderClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sw02_qt_LCD_SliderClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(sw02_qt_LCD_SliderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sw02_qt_LCD_SliderClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(sw02_qt_LCD_SliderClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sw02_qt_LCD_SliderClass->setStatusBar(statusBar);

        retranslateUi(sw02_qt_LCD_SliderClass);

        QMetaObject::connectSlotsByName(sw02_qt_LCD_SliderClass);
    } // setupUi

    void retranslateUi(QMainWindow *sw02_qt_LCD_SliderClass)
    {
        sw02_qt_LCD_SliderClass->setWindowTitle(QCoreApplication::translate("sw02_qt_LCD_SliderClass", "sw02_qt_LCD_Slider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sw02_qt_LCD_SliderClass: public Ui_sw02_qt_LCD_SliderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SW02_QT_LCD_SLIDER_H
