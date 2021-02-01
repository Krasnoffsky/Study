#ifndef TREE_H
#define TREE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Tree : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Tree(QObject *parent = 0);
    ~Tree();

signals:

private:
    QRectF boundingRect() const;
    QPixmap *spriteImage;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TREE_H
