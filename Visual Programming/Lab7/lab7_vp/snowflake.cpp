#include "snowflake.h"
#include <math.h>

Snowflake::Snowflake(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    spriteImage = new QPixmap("C:\\Study\\Visual Programming\\Lab7\\snowflake.png");
    gameTimer = new QTimer();
    connect(gameTimer, &QTimer::timeout, this, &Snowflake::slotGameTimer);
    gameTimer->start(5);
    srand(time(NULL));
}

Snowflake::~Snowflake()
{

}
QRectF Snowflake::boundingRect() const
{
    return QRectF(-12,-15,70,80);
}

QPainterPath Snowflake::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Snowflake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *spriteImage, 0, 0, 50, 50);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Snowflake::slotGameTimer()
{
    if(!scene()->collidingItems(this).isEmpty()){
        do {
            currDir = rand() % 8;
        } while(currDir == prevDir);

        prevDir = currDir;
    }

    if (currDir == 0){
        this->setY(this->y() - 1);
    }

    if (currDir == 1){
        this->setY(this->y() - 1);
        this->setX(this->x() + 1);
    }

    if (currDir == 2){
        this->setX(this->x() + 1);
    }

    if (currDir == 3){
        this->setX(this->x() + 1);
        this->setY(this->y() + 1);
    }

    if (currDir == 4){
        this->setY(this->y() + 1);
    }

    if (currDir == 5){
        this->setY(this->y() + 1);
        this->setX(this->x() - 1);
    }

    if (currDir == 6){
        this->setX(this->x() - 1);
    }

    if (currDir == 7){
        this->setX(this->x() - 1);
        this->setY(this->y() - 1);
    }

}


