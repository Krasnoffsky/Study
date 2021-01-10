#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->searchBox->setPlaceholderText("Поиск");

    connect(&dataControl, SIGNAL(sendToWidget(const QString,
                                             const QString,
                                             const QString,
                                             const QString,
                                             const QString)),this, SLOT(writeFromDatabase(const QString,
                                                                                               const QString,
                                                                                               const QString,
                                                                                               const QString,
                                                                                               const QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    ui->outputBox->clear();
    dataControl.readFromDatabase();

}


void MainWindow::on_testButton2_clicked()
{
//    QString name = ui->nameLine->text();
//    QString ingredients = ui->ingredientsBox->toPlainText();
//    QString recipe = ui->recipeBox->toPlainText();
//    QString type = "soup";
//    QString best = "false";
//    dataControl.addToDatabase(name, ingredients, recipe, type, best);
}

void MainWindow::writeFromDatabase(const QString name, const QString ingredients, const QString recipe, const QString type, const QString best)
{
    ui->outputBox->insertPlainText(name + "\n"
                             + type + "\n"
                             + ingredients + "\n"
                             + recipe + "\n_______________________________________\n");

}

void MainWindow::on_testButton3_clicked()
{
//    QString name = ui->nameLine->text();
//    dataControl.deleteFromDatabase(name);
}
