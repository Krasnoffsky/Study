#include "editrecordwidget.h"
#include "ui_editrecordwidget.h"

EditRecordWidget::EditRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditRecordWidget)
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

EditRecordWidget::~EditRecordWidget()
{
    delete ui;
}

void EditRecordWidget::on_addPicButton_clicked()
{
    currentPic = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    QImage image(currentPic);
    QPixmap pic = QPixmap::fromImage(image);
    ui->picLabel->setPixmap(pic);
    ui->picLabel->setPixmap(pic.scaled(picLabel_width,picLabel_height,Qt::KeepAspectRatio));

}

void EditRecordWidget::categoriesFirstButton_selected()
{
    currentCategory = "Первое блюдо";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesSecondButton_selected()
{
    currentCategory = "Второе блюдо";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesGarnishButton_selected()
{
    currentCategory = "Гарнир";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesSalatButton_selected()
{
    currentCategory = "Салаты";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesSauceButton_selected()
{
    currentCategory = "Соусы";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesDrinkButton_selected()
{
    currentCategory = "Напитки";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesMarinadeButton_selected()
{
    currentCategory = "Маринады";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesStockButton_selected()
{
    currentCategory = "Заготовки";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesDoughButton_selected()
{
    currentCategory = "Изделия из теста";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesSnackButton_selected()
{
    currentCategory = "Закуски";
    ui->selectCategoryButton->setText(currentCategory);
}

void EditRecordWidget::categoriesSweetButton_selected()
{
    currentCategory = "Сладости";
    ui->selectCategoryButton->setText(currentCategory);
}


void EditRecordWidget::on_saveButton_clicked()
{
    QString name = ui->nameLine->text();
    QString ingredients = ui->ingredientsBox->toPlainText();
    QString recipe = ui->recipeBox->toPlainText();

    if (currentPic == "")
        currentPic = "C:\\Study\\Visual Programming\\CourseWork\\Part2\\src\\default.jpg";

    QPixmap inPixmap;
    inPixmap.load(currentPic);
    QByteArray inByteArray;
    QBuffer inBuffer( &inByteArray );
    inBuffer.open( QIODevice::WriteOnly );
    inPixmap.save( &inBuffer, "PNG" );

    emit sendToWidgetUpdate(currentID, name, ingredients, recipe, currentCategory, inByteArray);
    QMessageBox::information(0, "Avocado", "Рецепт редактирован");
    close();

}

void EditRecordWidget::catchInfo(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic)
{
    ui->nameLine->setText(name);
    ui->recipeBox->setText(recipe);
    ui->ingredientsBox->setText(ingredients);
    ui->selectCategoryButton->setText(type);

    currentID = id;

    QPixmap img = QPixmap();

    img.loadFromData(pic);
    ui->picLabel->setPixmap(img.scaled(picLabel_width,picLabel_height,Qt::KeepAspectRatio));
}

void EditRecordWidget::on_cancelButton_clicked()
{
    close();
}
