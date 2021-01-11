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
    dataControl.readFromDatabase("READ_ALL");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeFromDatabase(const QString name, const QString ingredients, const QString recipe, const QString type, const QString best)
{
    if (best == "1")
        ui->outputBox->insertPlainText("★");
    ui->outputBox->insertPlainText(name + "\n"
                             + type + "\n"
                             + ingredients + "\n"
                             + recipe + "\n_______________________________________\n");

}

