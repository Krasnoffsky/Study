#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->searchBox->setPlaceholderText("Поиск");
    dataControl = new database;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    dataControl->updateDatabase();
    while (dataControl->query->next())
    {
        QString name = dataControl->query->value(0).toString();
        QString age = dataControl->query->value(1).toString();
        QString color = dataControl->query->value(2).toString();
        ui->textEdit->insertPlainText(name + " " + age + " " + color +"\n");
    }
}


void MainWindow::on_testButton2_clicked()
{

}
