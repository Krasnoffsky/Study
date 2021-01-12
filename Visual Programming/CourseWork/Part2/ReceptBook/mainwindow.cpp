#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->searchBox->setPlaceholderText("Поиск");

    connect(&dataControl, SIGNAL(sendToWidget(const int,
                                              const QString,
                                              const QString,
                                              const QString,
                                              const QString,
                                              const QString)),this, SLOT(writeFromDatabase(const int,
                                                                                          const QString,
                                                                                          const QString,
                                                                                          const QString,
                                                                                          const QString,
                                                                                          const QString)));
//    dataControl.readFromDatabase("READ_ALL");
    currentID = 1;

    recipesModel = new QSqlTableModel(this);
    recipesModel->setTable(TABLE_NAME);

    ui->recipesTable->setModel(recipesModel);
    ui->recipesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->recipesTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->recipesTable->resizeColumnsToContents();
    ui->recipesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->recipesTable->horizontalHeader()->setStretchLastSection(true);
    ui->recipesTable->setColumnHidden(1, true);
    ui->recipesTable->setColumnHidden(2, true);
    ui->recipesTable->setColumnHidden(3, true);
    ui->recipesTable->setColumnHidden(4, true);
    ui->recipesTable->horizontalHeader()->hide();
    ui->recipesTable->verticalHeader()->hide();

    recipesModel->select();

    ui->recipesTable->setModel(recipesModel);

    connect(ui->recipesTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                    this, SLOT(currentRecipe(QModelIndex)));

//    categoryFirst = new QAction();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeFromDatabase(const int id, const QString name, const QString ingredients, const QString recipe, const QString type, const QString best)
{
    ui->outputBox->clear();
    if (best == "1")
        ui->outputBox->insertPlainText("★");
    ui->outputBox->insertPlainText(name + "\n"
                             + type + "\n"
                             + ingredients + "\n"
                             + recipe + "\n_______________________________________\n");
    currentID = id;
    recipesModel->select();

}

void MainWindow::on_bestButton_clicked()
{
    ui->outputBox->clear();
    dataControl.readBestFromDatabase();
}

void MainWindow::on_pushButton_clicked()
{
    currentID += 1;
    ui->outputBox->clear();
    dataControl.readFromDatabase(currentID, "READ_CURRENT");
}

void MainWindow::currentRecipe(QModelIndex id)
{
    QString name = recipesModel->data(recipesModel->index(id.row(), 1)).toString();
    QString ingredients = recipesModel->data(recipesModel->index(id.row(), 2)).toString();
    QString recipe = recipesModel->data(recipesModel->index(id.row(), 1)).toString();
    ui->outputBox->setPlainText(name + "\n" + ingredients + "\n" + recipe);
}
