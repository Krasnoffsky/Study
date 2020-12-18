#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->resize(600,600);
    this->setFixedSize(600,600);

    ui->setupUi(this);

    scene   = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);  /// Ð£ÑÑ‚Ð°Ð½Ð°Ð²Ð»Ð¸Ð²Ð°ÐµÐ¼ Ð³Ñ€Ð°Ñ„Ð¸Ñ‡ÐµÑÐºÑƒÑŽ ÑÑ†ÐµÐ½Ñƒ Ð² graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Ð£ÑÑ‚Ð°Ð½Ð°Ð²Ð»Ð¸Ð²Ð°ÐµÐ¼ ÑÐ³Ð»Ð°Ð¶Ð¸Ð²Ð°Ð½Ð¸Ðµ
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// ÐžÑ‚ÐºÐ»ÑŽÑ‡Ð°ÐµÐ¼ ÑÐºÑ€Ð¾Ð»Ð»Ð±Ð°Ñ€ Ð¿Ð¾ Ð²ÐµÑ€Ñ‚Ð¸ÐºÐ°Ð»Ð¸
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// ÐžÑ‚ÐºÐ»ÑŽÑ‡Ð°ÐµÐ¼ ÑÐºÑ€Ð¾Ð»Ð»Ð±Ð°Ñ€ Ð¿Ð¾ Ð³Ð¾Ñ€Ð¸Ð·Ð¾Ð½Ñ‚Ð°Ð»Ð¸

    scene->setSceneRect(0,0,520,520);

    Snowflake = new snowflake();

    Snowflake->setPos(60,60);
    Snowflake->setZValue(2);
    scene->addItem(Snowflake);

    scene->addRect(0,0,520,20,QPen(Qt::NoPen),QBrush("#556B2F"));
    scene->addRect(0,0,20,520,QPen(Qt::NoPen),QBrush("#556B2F"));
    scene->addRect(0,500,520,20,QPen(Qt::NoPen),QBrush("#556B2F"));
    scene->addRect(500,0,20,520,QPen(Qt::NoPen),QBrush("#556B2F"));

    scene->addRect(250,250,200,150,QPen(Qt::black),QBrush("#8FBC8F"));
    scene->addRect(240,230,220,20,QPen(Qt::black),QBrush("#808000"));
    scene->addRect(250,400,200,10,QPen(Qt::black),QBrush(Qt::darkGray));
    scene->addRect(270,410,160,10,QPen(Qt::black),QBrush(Qt::darkGray));


    MainWindow *item = new MainWindow(this);
    item->setPos(280, 290);
    scene->addItem(item);
    MainWindow *item2 = new MainWindow(this);
    item2->setPos(380, 290);
    scene->addItem(item2);
}

Widget::~Widget()
{
    delete ui;
}
