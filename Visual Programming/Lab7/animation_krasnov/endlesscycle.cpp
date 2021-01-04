#include "endlesscycle.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QDebug>

endlesscycle::endlesscycle()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));
    background = QBrush(QColor(255, 255, 255));
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(12);
    home.load(temp);
    mouse.load(temp2);
}

void endlesscycle::setNewPos(int x, int y)
{
    if(bufferNumberOBJ == 5)
    {
        x_mouse = x;
        y_mouse = y;
        rect[bufferNumberOBJ].setX(x);
        rect[bufferNumberOBJ].setY(y);
    }
    else
    {
        rect[bufferNumberOBJ].setX(x);
        rect[bufferNumberOBJ].setY(y);
        rect[bufferNumberOBJ].setWidth(W);
        rect[bufferNumberOBJ].setHeight(H);
    }
}

bool endlesscycle::collision(int x, int y, int wOBJ, int hOBJ, int n)
{
    int CheckMinX, CheckMaxX, CheckMinY, CheckMaxY, interLeft, interTop, interRight, interBottom;
    ObjectMinX = x;
    ObjectMaxX = x + wOBJ;
    ObjectMinY = y;
    ObjectMaxY = y + hOBJ;

    for(int i = 0; i < n; i++)
    {
        CheckMinX = rect[i].x();
        CheckMaxX = rect[i].x() + rect[i].width();
        CheckMinY = rect[i].y();
        CheckMaxY = rect[i].y() + rect[i].height();

        interLeft = std::max(CheckMinX, ObjectMinX);
        interBottom = std::max(CheckMinY, ObjectMinY);
        interRight = std::min(CheckMaxX, ObjectMaxX);
        interTop = std::min(CheckMaxY, ObjectMaxY);

        if ((interLeft < interRight) && (interTop > interBottom))
        {
            bufferNumberOBJ = i;
            return true;
        }
    }
    return false;
}

void endlesscycle::move()
{
    x_mouse += speed_x;
    rect[5].setX(x_mouse);
    if(collision(x_mouse, y_mouse, wMouse, hMouse, 5))
    {
        x_mouse -= speed_x;
        speed_x *= -1;
        x_mouse += speed_x;
        rect[5].setX(x_mouse);
    }

    y_mouse += speed_y;
    rect[5].setY(y_mouse);
    if(collision(x_mouse, y_mouse, wMouse, hMouse, 5))
    {
        y_mouse -= speed_y;
        speed_y *= -1;
        y_mouse += speed_y;
        rect[5].setY(y_mouse);
    }
}

void endlesscycle::paint(QPainter *painter, QPaintEvent *event)
{
    qDebug() << rect[4].width() << " " << rect[4].height();
    move();

    painter->fillRect(event->rect(), background);

    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);

    painter->drawRect(rect[0].x(), rect[0].y(), rect[0].width(), rect[0].height());
    painter->drawRect(rect[1].x(), rect[1].y(), rect[1].width(), rect[1].height());
    painter->drawRect(rect[2].x(), rect[2].y(), rect[2].width(), rect[2].height());
    painter->drawRect(rect[3].x(), rect[3].y(), rect[3].width(), rect[3].height());
    painter->drawPixmap(rect[4].x(), rect[4].y(), rect[4].width(), rect[4].height(),QPixmap::fromImage(home));
    painter->drawPixmap(x_mouse, y_mouse, wMouse, hMouse, QPixmap::fromImage(mouse));
    painter->restore();
    painter->setPen(textPen);
    painter->setFont(textFont);
    painter->drawText(QRect(x_mouse, y_mouse, 30, -10), Qt::AlignCenter, QStringLiteral("Снежинка"));
}
