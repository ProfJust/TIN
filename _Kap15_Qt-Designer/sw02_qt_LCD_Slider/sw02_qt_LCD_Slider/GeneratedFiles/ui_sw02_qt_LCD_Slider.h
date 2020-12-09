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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sw02_qt_LCD_SliderClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sw02_qt_LCD_SliderClass)
    {
        if (sw02_qt_LCD_SliderClass->objectName().isEmpty())
            sw02_qt_LCD_SliderClass->setObjectName(QString::fromUtf8("sw02_qt_LCD_SliderClass"));
        sw02_qt_LCD_SliderClass->resize(600, 400);
        centralWidget = new QWidget(sw02_qt_LCD_SliderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 150, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 160, 75, 23));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(230, 270, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(170, 50, 181, 111));
        sw02_qt_LCD_SliderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sw02_qt_LCD_SliderClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        sw02_qt_LCD_SliderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sw02_qt_LCD_SliderClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sw02_qt_LCD_SliderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sw02_qt_LCD_SliderClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sw02_qt_LCD_SliderClass->setStatusBar(statusBar);

        retranslateUi(sw02_qt_LCD_SliderClass);
        QObject::connect(pushButton, SIGNAL(clicked()), sw02_qt_LCD_SliderClass, SLOT(minus()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), sw02_qt_LCD_SliderClass, SLOT(plus()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(sw02_qt_LCD_SliderClass);
    } // setupUi

    void retranslateUi(QMainWindow *sw02_qt_LCD_SliderClass)
    {
        sw02_qt_LCD_SliderClass->setWindowTitle(QCoreApplication::translate("sw02_qt_LCD_SliderClass", "sw02_qt_LCD_Slider", nullptr));
        pushButton->setText(QCoreApplication::translate("sw02_qt_LCD_SliderClass", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sw02_qt_LCD_SliderClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sw02_qt_LCD_SliderClass: public Ui_sw02_qt_LCD_SliderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SW02_QT_LCD_SLIDER_H
