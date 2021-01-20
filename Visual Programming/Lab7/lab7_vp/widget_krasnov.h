#ifndef WIDGET_KRASNOV_H
#define WIDGET_KRASNOV_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>

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
};

#endif // WIDGET_KRASNOV_H
