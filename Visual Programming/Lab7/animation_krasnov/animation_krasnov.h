#ifndef ANIMATION_KRASNOV_YAKUNIN_H
#define ANIMATION_KRASNOV_H

#include "endlesscycle.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Animation_Krasnov; }
QT_END_NAMESPACE

class Animation_Krasnov : public QWidget
{
    Q_OBJECT

public:
    Animation_Krasnov();

private:
    endlesscycle elc;
};
#endif // ANIMATION_KRASNOV_H
