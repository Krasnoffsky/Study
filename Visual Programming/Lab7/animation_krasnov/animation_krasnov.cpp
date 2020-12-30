#include "widget.h"
#include "animation_krasnov.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

Animation_Krasnov::Animation_Krasnov()
{
    setWindowTitle(tr("Krasnov-IP814"));

    widget *native = new widget(&elc, this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, native, &widget::animate);
    timer->start(50);
}

