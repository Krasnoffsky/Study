#include "figures_krasnov.h"

figures_krasnov::figures_krasnov()
{

}

void figures_krasnov::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QPainter qp(this);
  drawBorders(&qp);
}

void figures_krasnov::drawBorders(QPainter *qp) {

  QPen pen(Qt::black, 2, Qt::SolidLine);

  qp->setPen(pen);
  qp->drawRect(10, 10, 680, 680);

}
