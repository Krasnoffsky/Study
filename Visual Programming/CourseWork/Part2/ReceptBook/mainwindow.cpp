#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);

    newRecord = new NewRecordWidget;
    confirmDeleteDialog = new Dialog;

    connect(newRecord,SIGNAL(sendToWidget(QString,
                                          QString,
                                          QString,
                                          QString,
                                          QString)), this, SLOT(addNewRecipe(QString,
                                                                             QString,
                                                                             QString,
                                                                             QString,
                                                                             QString)));

    ui->searchBox->setPlaceholderText("Поиск");

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
    ui->recipesTable->setColumnHidden(5, true);
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

    picLabel_width = ui->picLabel->width();
    picLabel_height = ui->picLabel->height();

    currentCategory = "Все рецепты";

    flag_best = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currentRecipe(QModelIndex id)
{
    QString name = recipesModel->data(recipesModel->index(id.row(), 0)).toString();
    QString ingredients = recipesModel->data(recipesModel->index(id.row(), 1)).toString();
    QString recipe = recipesModel->data(recipesModel->index(id.row(), 2)).toString();
    QString type = recipesModel->data(recipesModel->index(id.row(), 3)).toString();
    QString best = recipesModel->data(recipesModel->index(id.row(), 4)).toString();
    QString pic_path = recipesModel->data(recipesModel->index(id.row(), 5)).toString();
    QImage pic(pic_path);

    if (best == "1"){
        ui->nameLabel->setText(name + " ★");
        ui->edit_bestButton->setText("Удалить из избранного");
    }
    else {
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("Добавить в избранное");
    }
    ui->outputBox->setPlainText("Категория: " + type + "\nИнгредиенты:\n" + ingredients + "\nРецепт: \n" + recipe);

    recipePic = QPixmap::fromImage(pic);
    ui->picLabel->setPixmap(recipePic);
    ui->picLabel->setPixmap(recipePic.scaled(picLabel_width,picLabel_height,Qt::KeepAspectRatio));

    currentID = id.row();
}

void MainWindow::categoriesAllButton_selected()
{
    currentCategory = "Все рецепты";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesFirstButton_selected()
{
    currentCategory = "Первое блюдо";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSecondButton_selected()
{
    currentCategory = "Второе блюдо";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesGarnishButton_selected()
{
    currentCategory = "Гарнир";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSalatButton_selected()
{
    currentCategory = "Салаты";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSauceButton_selected()
{
    currentCategory = "Соусы";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesDrinkButton_selected()
{
    currentCategory = "Напитки";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesMarinadeButton_selected()
{
    currentCategory = "Маринады";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesStockButton_selected()
{
    currentCategory = "Заготовки";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesDoughButton_selected()
{
    currentCategory = "Изделия из теста";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSnackButton_selected()
{
    currentCategory = "Закуски";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSweetButton_selected()
{
    currentCategory = "Сладости";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::on_bestButton_clicked()
{
    if (flag_best){
        flag_best = false;
        ui->bestButton->setText("Показать избранное");
    }
    else {
        flag_best = true;
        ui->bestButton->setText("Показать всё");
    }

    categorySelected();
}


void MainWindow::on_deleteButton_clicked()
{
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

    if (best == '1' ){
        dataControl.editBestInDatabase(currentID + 1, 0);
        ui->nameLabel->setText(name + " ★");
        ui->edit_bestButton->setText("Удалить из избранного");
    }
    else {
        dataControl.editBestInDatabase(currentID + 1, 1);
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("Добавить в избранное");
    }
    recipesModel->select();
    ui->recipesTable->selectRow(currentID);
    categorySelected();
}

void MainWindow::categorySelected()
{
    int rowNumber = recipesModel->rowCount();
    if (currentCategory == "Все рецепты")
        for (int i = 0 ; i < rowNumber; i++){
            if (flag_best && recipesModel->data(recipesModel->index(i, 4)).toString() != '1')
                ui->recipesTable->setRowHidden(i, true);
            else
                ui->recipesTable->setRowHidden(i, false);
        }

    else
        for (int i = 0; i < rowNumber; i++){
            if (recipesModel->data(recipesModel->index(i, 3)).toString() != currentCategory)
                ui->recipesTable->setRowHidden(i, true);
            else if (flag_best && recipesModel->data(recipesModel->index(i, 4)).toString() != '1')
                ui->recipesTable->setRowHidden(i, true);
            else
               ui->recipesTable->setRowHidden(i, false);
       }
}

void MainWindow::on_editButton_clicked()
{

}

void MainWindow::on_addButton_clicked()
{
        newRecord->show();
}

void MainWindow::addNewRecipe(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &pic)
{
    dataControl.addToDatabase(name, ingredients, recipe, type, 0, pic);

    recipesModel->select();
}
