#pragma once
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget);

protected:
    void advance(int phase);

private:
    qreal angle, speed;  
    void doCollision();
};