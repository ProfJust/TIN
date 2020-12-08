/********************************************************************************
** Form generated from reading UI file 'primegame_maingui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMEGAME_MAINGUI_H
#define UI_PRIMEGAME_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimeGame_MainGUI
{
public:
    QWidget *centralWidget;
    QPushButton *StartButton;
    QPushButton *ExitButton;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textfield_points_Player1;
    QLabel *label_3;
    QTextBrowser *textfield_points_Player2;
    QTextBrowser *textField_Auswahl;
    QGroupBox *groupBox;
    QLabel *label_Win;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PrimeGame_MainGUI)
    {
        if (PrimeGame_MainGUI->objectName().isEmpty())
            PrimeGame_MainGUI->setObjectName(QString::fromUtf8("PrimeGame_MainGUI"));
        PrimeGame_MainGUI->resize(1920, 1080);
        centralWidget = new QWidget(PrimeGame_MainGUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(20, 810, 221, 51));
        QFont font;
        font.setPointSize(12);
        StartButton->setFont(font);
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(270, 810, 191, 51));
        ExitButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 361, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(950, 90, 221, 41));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        textfield_points_Player1 = new QTextBrowser(centralWidget);
        textfield_points_Player1->setObjectName(QString::fromUtf8("textfield_points_Player1"));
        textfield_points_Player1->setGeometry(QRect(950, 140, 161, 71));
        textfield_points_Player1->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1420, 90, 251, 41));
        label_3->setFont(font2);
        textfield_points_Player2 = new QTextBrowser(centralWidget);
        textfield_points_Player2->setObjectName(QString::fromUtf8("textfield_points_Player2"));
        textfield_points_Player2->setGeometry(QRect(1420, 140, 151, 71));
        textfield_points_Player2->setFont(font2);
        textField_Auswahl = new QTextBrowser(centralWidget);
        textField_Auswahl->setObjectName(QString::fromUtf8("textField_Auswahl"));
        textField_Auswahl->setGeometry(QRect(950, 220, 931, 711));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 110, 861, 681));
        label_Win = new QLabel(centralWidget);
        label_Win->setObjectName(QString::fromUtf8("label_Win"));
        label_Win->setGeometry(QRect(840, 950, 731, 51));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_Win->setFont(font3);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1620, 10, 271, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8("Resources/images/w-hs_pagelogo.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 0, 1031, 71));
        label_5->setPixmap(QPixmap(QString::fromUtf8("Resources/images/header.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1460, 940, 441, 91));
        label_6->setPixmap(QPixmap(QString::fromUtf8("Resources/images/author.png")));
        label_6->setScaledContents(true);
        PrimeGame_MainGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PrimeGame_MainGUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 21));
        PrimeGame_MainGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PrimeGame_MainGUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PrimeGame_MainGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PrimeGame_MainGUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PrimeGame_MainGUI->setStatusBar(statusBar);

        retranslateUi(PrimeGame_MainGUI);

        StartButton->setDefault(true);


        QMetaObject::connectSlotsByName(PrimeGame_MainGUI);
    } // setupUi

    void retranslateUi(QMainWindow *PrimeGame_MainGUI)
    {
        PrimeGame_MainGUI->setWindowTitle(QCoreApplication::translate("PrimeGame_MainGUI", "PrimeGameQt Version 1.5", nullptr));
        StartButton->setText(QCoreApplication::translate("PrimeGame_MainGUI", "Start the Game", nullptr));
        ExitButton->setText(QCoreApplication::translate("PrimeGame_MainGUI", "Exit", nullptr));
        label->setText(QCoreApplication::translate("PrimeGame_MainGUI", "Der aktuelle Spielstand: ", nullptr));
        label_2->setText(QCoreApplication::translate("PrimeGame_MainGUI", "Spieler 1:", nullptr));
        label_3->setText(QCoreApplication::translate("PrimeGame_MainGUI", "Spieler 2:", nullptr));
        groupBox->setTitle(QString());
        label_Win->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PrimeGame_MainGUI: public Ui_PrimeGame_MainGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMEGAME_MAINGUI_H
