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

    categoryAll = new QAction();
    categoryFirst = new QAction();
    categorySecond = new QAction();
    categoryGarnish = new QAction();
    categorySalat = new QAction();
    categorySauce = new QAction();
    categoryDrink = new QAction();
    categoryMarinade = new QAction();
    categoryStock = new QAction();
    categoryDough = new QAction();
    categorySnack = new QAction();
    categorySweet = new QAction();

    categoryAll->setText("Все рецепты");
    categoryFirst->setText("Первое блюдо");
    categorySecond->setText("Второе блюдо");
    categoryGarnish->setText("Гарнир");
    categorySalat->setText("Салаты");
    categorySauce->setText("Соусы");
    categoryDrink->setText("Напитки");
    categoryMarinade->setText("Маринады");
    categoryStock->setText("Заготовки");
    categoryDough->setText("Изделия из теста");
    categorySnack->setText("Закуски");
    categorySweet->setText("Сладости");

    categoriesMenu = new QMenu;
    categoriesMenu->addAction(categoryAll);
    categoriesMenu->addAction(categoryFirst);
    categoriesMenu->addAction(categorySecond);
    categoriesMenu->addAction(categoryGarnish);
    categoriesMenu->addAction(categorySalat);
    categoriesMenu->addAction(categorySauce);
    categoriesMenu->addAction(categoryDrink);
    categoriesMenu->addAction(categoryMarinade);
    categoriesMenu->addAction(categoryStock);
    categoriesMenu->addAction(categoryDough);
    categoriesMenu->addAction(categorySnack);
    categoriesMenu->addAction(categorySweet);
    categoriesMenu->setMaximumWidth(201);
    categoriesMenu->setMinimumWidth(201);

    ui->categoriesButton->setMenu(categoriesMenu);

    connect(categoryAll, SIGNAL(triggered()), SLOT(categoriesAllButton_selected()));
    connect(categoryFirst, SIGNAL(triggered()), SLOT(categoriesFirstButton_selected()));
    connect(categorySecond, SIGNAL(triggered()), SLOT(categoriesSecondButton_selected()));
    connect(categoryGarnish, SIGNAL(triggered()), SLOT(categoriesGarnishButton_selected()));
    connect(categorySalat, SIGNAL(triggered()), SLOT(categoriesSalatButton_selected()));
    connect(categorySauce, SIGNAL(triggered()), SLOT(categoriesSauceButton_selected()));
    connect(categoryDrink, SIGNAL(triggered()), SLOT(categoriesDrinkButton_selected()));
    connect(categoryMarinade, SIGNAL(triggered()), SLOT(categoriesMarinadeButton_selected()));
    connect(categoryStock, SIGNAL(triggered()), SLOT(categoriesStockButton_selected()));
    connect(categoryDough, SIGNAL(triggered()), SLOT(categoriesDoughButton_selected()));
    connect(categorySnack, SIGNAL(triggered()), SLOT(categoriesSnackButton_selected()));
    connect(categorySweet, SIGNAL(triggered()), SLOT(categoriesSweetButton_selected()));

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

void MainWindow::currentRecipe(QModelIndex id)
{
    QString name = recipesModel->data(recipesModel->index(id.row(), 0)).toString();
    QString ingredients = recipesModel->data(recipesModel->index(id.row(), 1)).toString();
    QString recipe = recipesModel->data(recipesModel->index(id.row(), 2)).toString();
    QString type = recipesModel->data(recipesModel->index(id.row(), 3)).toString();
    QString best = recipesModel->data(recipesModel->index(id.row(), 4)).toString();
    if (best == "1"){
        ui->nameLabel->setText(name + " ★");
        ui->edit_bestButton->setText("Удалить из избранного");
    }
    else {
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("Добавить в избранное");
    }
    ui->outputBox->setPlainText("Категория: " + type + "\nИнгредиенты:\n" + ingredients + "\nРецепт: \n" + recipe);
    currentID = id.row();
}

void MainWindow::categoriesAllButton_selected()
{
    ui->categoriesButton->setText("Все рецепты");
}

void MainWindow::categoriesFirstButton_selected()
{
    ui->categoriesButton->setText("Первое блюдо");
}

void MainWindow::categoriesSecondButton_selected()
{
    ui->categoriesButton->setText("Второе блюдо");
}

void MainWindow::categoriesGarnishButton_selected()
{
    ui->categoriesButton->setText("Гарнир");
}

void MainWindow::categoriesSalatButton_selected()
{
    ui->categoriesButton->setText("Салаты");
}

void MainWindow::categoriesSauceButton_selected()
{
    ui->categoriesButton->setText("Соусы");
}

void MainWindow::categoriesDrinkButton_selected()
{
    ui->categoriesButton->setText("Напитки");
}

void MainWindow::categoriesMarinadeButton_selected()
{
    ui->categoriesButton->setText("Маринады");
}

void MainWindow::categoriesStockButton_selected()
{
    ui->categoriesButton->setText("Заготовки");
}

void MainWindow::categoriesDoughButton_selected()
{
    ui->categoriesButton->setText("Изделия из теста");
}

void MainWindow::categoriesSnackButton_selected()
{
    ui->categoriesButton->setText("Закуски");
}

void MainWindow::categoriesSweetButton_selected()
{
    ui->categoriesButton->setText("Сладости");
}

void MainWindow::on_bestButton_clicked()
{
    ui->outputBox->clear();
    dataControl.readBestFromDatabase();
}


void MainWindow::on_deleteButton_clicked()
{
    confirmDeleteDialog = new Dialog;
    switch(confirmDeleteDialog->exec()){
        case QDialog::Accepted:
            dataControl.deleteFromDatabase(currentID + 1);
            recipesModel->select();
            ui->nameLabel->clear();
            ui->outputBox->clear();
            ui->picLabel->clear();
        case QDialog::Rejected:
            break;
        default:
            break;
    }
}

void MainWindow::on_edit_bestButton_clicked()
{
    QString name = recipesModel->data(recipesModel->index(currentID, 0)).toString();
    QString best = recipesModel->data(recipesModel->index(currentID, 4)).toString();

    if (best == '1' )
        dataControl.editBestInDatabase(currentID + 1, 0);
    else
        dataControl.editBestInDatabase(currentID + 1, 1);
    recipesModel->select();

    if (best == '1'){
        ui->nameLabel->setText(name + " ★");
        ui->edit_bestButton->setText("Удалить из избранного");
    }
    else {
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("Добавить в избранное");
    }
    ui->recipesTable->selectRow(currentID);
}
