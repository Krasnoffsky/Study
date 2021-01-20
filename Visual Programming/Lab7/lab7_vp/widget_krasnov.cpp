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

    scene->setSceneRect(0, 0, 700, 700);
    scene->addRect(30,30,58,20,QPen(Qt::NoPen),Qt::green);
    scene->addRect(300,500,120,80,QPen(Qt::NoPen),Qt::blue);
    scene->addRect(39,300,98,157,QPen(Qt::NoPen),Qt::red);
    scene->addLine(10, 10, 10, 690);
    scene->addLine(10, 10, 690, 10);
    scene->addLine(690, 10, 690, 690);
    scene->addLine(690, 690, 10, 690);

    sf = new Snowflake;
    sf->setPos(300, 300);
    scene->addItem(sf);

    ch = new Tree;
    ch->setPos(200, 200);
    scene->addItem(ch);

}

widget_krasnov::~widget_krasnov()
{
    delete ui;
}
