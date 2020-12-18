#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>

#include <snowflake.h>
#include <mainwindow.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    snowflake *Snowflake;
    //QTimer *timerTarget;        // Ð¢Ð°Ð¹Ð¼ÐµÑ€ Ð´Ð»Ñ ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ñ Ð¼Ð¸ÑˆÐµÐ½ÐµÐ¹

};
#endif // WIDGET_H
