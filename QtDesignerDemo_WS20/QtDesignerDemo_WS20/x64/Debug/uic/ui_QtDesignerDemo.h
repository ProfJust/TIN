/********************************************************************************
** Form generated from reading UI file 'QtDesignerDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDESIGNERDEMO_H
#define UI_QTDESIGNERDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDesignerDemoClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Minus;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_Plus;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDesignerDemoClass)
    {
        if (QtDesignerDemoClass->objectName().isEmpty())
            QtDesignerDemoClass->setObjectName(QString::fromUtf8("QtDesignerDemoClass"));
        QtDesignerDemoClass->resize(901, 400);
        centralWidget = new QWidget(QtDesignerDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 50, 391, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Minus = new QPushButton(verticalLayoutWidget);
        pushButton_Minus->setObjectName(QString::fromUtf8("pushButton_Minus"));

        horizontalLayout_2->addWidget(pushButton_Minus);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setDigitCount(2);
        lcdNumber_2->setProperty("intValue", QVariant(50));

        horizontalLayout_2->addWidget(lcdNumber_2);

        pushButton_Plus = new QPushButton(verticalLayoutWidget);
        pushButton_Plus->setObjectName(QString::fromUtf8("pushButton_Plus"));

        horizontalLayout_2->addWidget(pushButton_Plus);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        QtDesignerDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtDesignerDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 901, 21));
        QtDesignerDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDesignerDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtDesignerDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtDesignerDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtDesignerDemoClass->setStatusBar(statusBar);

        retranslateUi(QtDesignerDemoClass);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(pushButton_Plus, SIGNAL(clicked()), QtDesignerDemoClass, SLOT(slotPlus()));
        QObject::connect(pushButton_Minus, SIGNAL(clicked()), QtDesignerDemoClass, SLOT(slotMinus()));

        QMetaObject::connectSlotsByName(QtDesignerDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDesignerDemoClass)
    {
        QtDesignerDemoClass->setWindowTitle(QCoreApplication::translate("QtDesignerDemoClass", "QtDesignerDemo", nullptr));
        label->setText(QCoreApplication::translate("QtDesignerDemoClass", "TIN - WHS goes Qt   -  Qt DesignerDemo", nullptr));
        pushButton_Minus->setText(QCoreApplication::translate("QtDesignerDemoClass", "<", nullptr));
        pushButton_Plus->setText(QCoreApplication::translate("QtDesignerDemoClass", ">", nullptr));
        label_2->setText(QCoreApplication::translate("QtDesignerDemoClass", "<html><head/><body><p><img src=\":/QtDesignerDemo/WH_logo_CMYK_02.jpg\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDesignerDemoClass: public Ui_QtDesignerDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDESIGNERDEMO_H
