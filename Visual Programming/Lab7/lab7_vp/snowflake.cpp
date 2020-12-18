#include "snowflake.h"
#include <math.h>

snowflake::snowflake(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    spriteImage = new QPixmap("snowflake.png");
    gameTimer = new QTimer();
    connect(gameTimer, &QTimer::timeout, this, &snowflake::slotGameTimer);
    gameTimer->start(5);
}

snowflake::~snowflake()
{

}

QRectF snowflake::boundingRect() const
{
    return QRectF(-12,-15,70,80);
}

QPainterPath snowflake::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void snowflake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10, -10, *spriteImage, 0, 0, 60, 65);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void snowflake::slotGameTimer()
{
        if(!scene()->collidingItems(this).isEmpty()){
            right = !right;
        }
        if (right){
            this->setX(this->x() + 1);
        } else {
            this->setX(this->x() - 1);
        }
        if (check){
            this ->setY(this->y() + 0.3);
        } else
            this ->setY(this->y() - 0.3);
        if(!scene()->collidingItems(this).isEmpty()){
            down = !down;

            if(this->y() - 30 <= 5)
                check = !check;
            if(this->y() + 40 >= 490)
                check = !check;

        }
        if (down){
            this->setY(this->y() + 0.3);
        } else {
            this->setY(this->y() - 0.3);
        }

    if(this->x() - 30 < 0){
        this->setX(30);
    }
    if(this->x() + 30 > 520){
        this->setX(520 - 30);
    }

    if(this->y() - 30 < 0){
        this->setY(30);
    }
    if(this->y() + 30 > 520){
        this->setY(520 - 30);
    }

    //QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));

}

