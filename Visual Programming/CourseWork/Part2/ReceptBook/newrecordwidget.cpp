#include "newrecordwidget.h"
#include "ui_newrecordwidget.h"

NewRecordWidget::NewRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRecordWidget)
{
    ui->setupUi(this);
}

NewRecordWidget::~NewRecordWidget()
{
    delete ui;
}
