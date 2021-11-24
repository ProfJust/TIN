#include "QGraphicsSzene_01.h"

//https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_QGraphicsScene.php#google_vignette
//https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_animation.php


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QBrush>
#include <QPen>
#include <QList>
#include <QGraphicsTextItem>

QGraphicsSzene_01::QGraphicsSzene_01(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("QGraphicScene 01");
    QPen blackPen;
    blackPen.setWidth(7);
    blackPen.setColor(Qt::black);

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    view->setGeometry(0, 0, 680, 500);
    setCentralWidget(view);    

    QGraphicsEllipseItem* ellipse = scene->addEllipse(10, 10, 200, 200);
    ellipse->setBrush(Qt::red);

    QGraphicsRectItem* rect = scene->addRect(-100, -100, 200, 200);
    rect->setBrush(Qt::blue);
    rect->setPen(blackPen);  

    // Alle Kollisionen mit dem Rechteck heraussuchen und in Liste speichern 
    QList<QGraphicsItem*> liste_kollisionen = scene->collidingItems(rect);

    if (!liste_kollisionen.isEmpty())    {
        // collision !!!
        qDebug(" collision detected");
        qDebug() << "==================";
        qDebug() << liste_kollisionen;
        qDebug() << liste_kollisionen[0];

        QGraphicsTextItem* text = scene->addText("collision detected");
        text->setPos(300, 0);
        //liste_kollisionen[0]->setPen(Qt::red);
        liste_kollisionen[0]->setFlag(QGraphicsItem::ItemIsMovable, true);
    }
}

//ellipse->setFlag(QGraphicsItem.ItemIsMovable);

