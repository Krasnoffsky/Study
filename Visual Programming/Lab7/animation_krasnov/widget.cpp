#include "widget.h"
#include "endlesscycle.h"

#include <QPainter>
#include <QTimer>


widget::widget(endlesscycle *elc, QWidget *parent)
    : QWidget(parent), elc(elc)
{
    setFixedSize(500, 500);
}

void widget::animate()
{
    update();
}

void widget::mousePressEvent(QMouseEvent* event)
{
    if( (event->button() == Qt::LeftButton) and
         elc->collision(event->x(), event->y(), 10, 10, 6) )
    {
        elc->speed_x = 0;
        elc->speed_y = 0;
    }

    else if((event->button() == Qt::RightButton))
    {
        elc->W = elc->rect[elc->bufferNumberOBJ].width();
        elc->H = elc->rect[elc->bufferNumberOBJ].height();
        elc->setNewPos(event->x(), event->y());
        elc->speed_x = 10;
        elc->speed_y = 10;
    }
}

void widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    elc->paint(&painter, event);
    painter.end();
}
