#include "newrecordwidget.h"
#include "ui_newrecordwidget.h"

NewRecordWidget::NewRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRecordWidget)
{

    ui->setupUi(this);

    ui->nameLine->setPlaceholderText("Название рецепта");
    ui->ingredientsBox->setPlaceholderText("Ингредиенты");
    ui->recipeBox->setPlaceholderText("Рецепт");

    picLabel_width = ui->picLabel->width();
    picLabel_height = ui->picLabel->height();

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

    ui->selectCategoryButton->setMenu(categoriesMenu);

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

    currentPic = "";
    currentCategory = "";
}

NewRecordWidget::~NewRecordWidget()
{
    delete ui;
}

void NewRecordWidget::on_addPicButton_clicked()
{
    currentPic = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    QImage image(currentPic);
    QPixmap pic = QPixmap::fromImage(image);
    ui->picLabel->setPixmap(pic);
    ui->picLabel->setPixmap(pic.scaled(picLabel_width,picLabel_height,Qt::KeepAspectRatio));
}

void NewRecordWidget::categoriesFirstButton_selected()
{
    currentCategory = "Первое блюдо";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesSecondButton_selected()
{
    currentCategory = "Второе блюдо";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesGarnishButton_selected()
{
    currentCategory = "Гарнир";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesSalatButton_selected()
{
    currentCategory = "Салаты";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesSauceButton_selected()
{
    currentCategory = "Соусы";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesDrinkButton_selected()
{
    currentCategory = "Напитки";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesMarinadeButton_selected()
{
    currentCategory = "Маринады";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesStockButton_selected()
{
    currentCategory = "Заготовки";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesDoughButton_selected()
{
    currentCategory = "Изделия из теста";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesSnackButton_selected()
{
    currentCategory = "Закуски";
    ui->selectCategoryButton->setText(currentCategory);
}

void NewRecordWidget::categoriesSweetButton_selected()
{
    currentCategory = "Сладости";
    ui->selectCategoryButton->setText(currentCategory);
}


void NewRecordWidget::on_saveButton_clicked()
{
    QString name = ui->nameLine->text();
    QString ingredients = ui->ingredientsBox->toPlainText();
    QString recipe = ui->recipeBox->toPlainText();

    if (name != "" && ingredients != "" && recipe != "" && currentCategory != ""){
        if (currentPic == "")
            currentPic = "C:\\Study\\Visual Programming\\CourseWork\\Part2\\src\\default.jpg";
        emit sendToWidget(name, ingredients, recipe, currentCategory, currentPic);
        QMessageBox::information(0, "Avocado", "Новый рецепт добавлен");
        close();
    }
    else {
        QMessageBox::information(0, "Avocado", "Заполните все поля");
    }

}
