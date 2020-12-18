#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QDebug>
#include <QCursor>

#include <windows.h>

class snowflake : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit snowflake(QObject *parent = nullptr);
    ~snowflake();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

private slots:
    void slotGameTimer();

private:
    bool shot;
    bool right = true;
    bool down = true;
    bool check = true;
    QPixmap *spriteImage;
    QTimer *gameTimer;
};

#endif // SNOWFLAKE_H
