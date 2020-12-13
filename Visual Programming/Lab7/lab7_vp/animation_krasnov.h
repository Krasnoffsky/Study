#ifndef ANIMATION_KRASNOV_H
#define ANIMATION_KRASNOV_H

#include <QWidget>
#include <paint_krasnov.h>

namespace Ui {animation_krasnov; }

class animation_krasnov : public QWidget
{
    Q_OBJECT
public:
    animation_krasnov();

private:
    paint_krasnov elc;
};

#endif // ANIMATION_KRASNOV_H
