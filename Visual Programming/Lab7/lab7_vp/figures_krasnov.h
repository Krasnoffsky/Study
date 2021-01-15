#ifndef FIGURES_KRASNOV_H
#define FIGURES_KRASNOV_H

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>


class figures_krasnov : public QWidget
{
    Q_OBJECT

public:
    figures_krasnov();
    void paintEvent(QPaintEvent *event);
    void drawBorders(QPainter *qp);
};

#endif // FIGURES_KRASNOV_H
