#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class MainWindow : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();

signals:

private:
    QRectF boundingRect() const;
    QPixmap *spriteImage;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAINWINDOW_H
