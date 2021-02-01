#ifndef WIDGET_KRASNOV_H
#define WIDGET_KRASNOV_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "windows.h"
#include <QTimer>
#include <snowflake.h>
#include <tree.h>

namespace Ui {
class widget_krasnov;
}

class widget_krasnov : public QWidget
{
    Q_OBJECT

public:
    explicit widget_krasnov(QWidget *parent = nullptr);
    ~widget_krasnov();

private:
    Ui::widget_krasnov *ui;
    QGraphicsScene *scene;
    QTimer timer;

    Snowflake *sf;
    Tree *ch;

};

#endif // WIDGET_KRASNOV_H
