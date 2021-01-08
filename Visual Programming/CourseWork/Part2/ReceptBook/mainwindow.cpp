#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->searchBox->setPlaceholderText("Поиск");
    dataControl = new database;
    connect(dataControl, SIGNAL(sendToWidget(const QString name,
                                             const QString ingredients,
                                             const QString recipe,
                                             const QString type)),this, SLOT(writeFromDatabase(const QString name,
                                                                                               const QString ingredients,
                                                                                               const QString recipe,
                                                                                               const QString type)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    ui->textEdit->clear();
    dataControl->readFromDatabase();

}


void MainWindow::on_testButton2_clicked()
{
    QString name = "Jhon";
    QString ingredients = "paper";
    QString recipe = "Some cheese";
    QString type = "soup";
    QString best = "false";
    dataControl->addToDatabase(name, ingredients, recipe, type, best);
}

void MainWindow::writeFromDatabase(const QString name, const QString ingredients, const QString recipe, const QString type)
{
    ui->textEdit->setPlainText(name + " "
                             + ingredients + " "
                             + recipe + " "
                             + type + "\n");

}
