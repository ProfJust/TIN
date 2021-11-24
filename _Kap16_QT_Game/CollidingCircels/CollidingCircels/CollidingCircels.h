#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CollidingCircels.h"

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class CollidingCircels : public QMainWindow
{
    Q_OBJECT

public:
    CollidingCircels(QWidget *parent = Q_NULLPTR);
    ~CollidingCircels();

private:
    Ui::CollidingCircelsClass ui;

    QGraphicsScene* scene;
    QTimer* timer;
};
