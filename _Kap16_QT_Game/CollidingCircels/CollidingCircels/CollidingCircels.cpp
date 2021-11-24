#include "CollidingCircels.h"
#include "myitem.h"
//https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_QGraphicsScene.php#google_vignette
//https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_QGraphicsScene_QGraphicsItems.php
//https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_animation.php

CollidingCircels::CollidingCircels(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(scene);
    
    // anti-aliasing
    view->setRenderHint(QPainter::Antialiasing);

    //
    // The bounding rectangle of the scene
    // The scene rectangle defines the extent of the scene.
    // It is primarily used by QGraphicsView
    // to determine the view's default scrollable area,
    // and by QGraphicsScene to manage item indexing.
    // void	setSceneRect(qreal x, qreal y, qreal w, qreal h)
    scene->setSceneRect(-200, -200, 300, 300);

    QLineF topLine(scene->sceneRect().topLeft(),
        scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(),
        scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(),
        scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(),
        scene->sceneRect().bottomRight());

    QPen myPen = QPen(Qt::red);

    scene->addLine(topLine, myPen);
    scene->addLine(leftLine, myPen);
    scene->addLine(rightLine, myPen);
    scene->addLine(bottomLine, myPen);

    // adding myItems to the scene
    int itemCount = 20;
    for (int i = 0; i < itemCount; i++)
    {
        MyItem* item = new MyItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000);

    setCentralWidget(view);
}
CollidingCircels::~CollidingCircels() {
     
}