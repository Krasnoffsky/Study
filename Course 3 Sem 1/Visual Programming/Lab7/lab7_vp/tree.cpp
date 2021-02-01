#include "tree.h"

Tree::Tree(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Tree::~Tree()
{

}

QRectF Tree::boundingRect() const
{
    return QRectF (-12,-15,70,100);
}

void Tree::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    spriteImage = new QPixmap("C:\\Study\\Visual Programming\\Lab7\\christmas_tree.png");
    painter->drawPixmap(-10, -10, *spriteImage, 0, 0, 60, 90);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tree::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void Tree::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Tree::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
