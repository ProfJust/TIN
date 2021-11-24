#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QGraphicsSzene_01.h"
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


class QGraphicsSzene_01 : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsSzene_01(QWidget *parent = Q_NULLPTR);

    

private:
    Ui::QGraphicsSzene_01Class ui;
};
