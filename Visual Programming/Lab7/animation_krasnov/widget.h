#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <endlesscycle.h>

class endlesscycle;

class widget : public QWidget
{
Q_OBJECT
public:
    widget(endlesscycle *helper, QWidget *parent);

public slots:
    void mousePressEvent(QMouseEvent *event) override;
    void animate();

private:
    void paintEvent(QPaintEvent *event) override;
    endlesscycle *elc;
};

#endif // WIDGET_H
