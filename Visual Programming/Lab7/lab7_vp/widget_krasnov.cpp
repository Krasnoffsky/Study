#include "widget_krasnov.h"
#include "ui_widget_krasnov.h"

widget_krasnov::widget_krasnov(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_krasnov)
{
    ui->setupUi(this);
    this->resize(700, 700);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(10, 10, 680, 680);
    scene->addRect(30,30,58,20,QPen(Qt::NoPen),QBrush("#556B2F"));
}

widget_krasnov::~widget_krasnov()
{
    delete ui;
}
