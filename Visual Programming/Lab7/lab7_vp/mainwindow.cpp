#include "mainwindow.h"

MainWindow::MainWindow(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MainWindow::~MainWindow()
{

}

QRectF MainWindow::boundingRect() const
{
    return QRectF (-12,-15,70,100);
}

void MainWindow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    spriteImage = new QPixmap("window.png");
    painter->drawPixmap(-10, -10, *spriteImage, 0, 0, 60, 90);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MainWindow::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MainWindow::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
