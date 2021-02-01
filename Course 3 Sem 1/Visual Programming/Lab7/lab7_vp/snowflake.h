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
#include <cstdlib>
#include <time.h>

#include <windows.h>

class Snowflake : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    explicit Snowflake(QObject *parent = nullptr);
    ~Snowflake();

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
    int prevDir = 1;
    int currDir = 1;
};

#endif // SNOWFLAKE_H
