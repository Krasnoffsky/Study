#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QDialog>
#include <QMainWindow>
#include <QMenu>
#include <QSqlTableModel>
#include "database.h"
#include "dialog.h"
#include "newrecordwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void currentRecipe(QModelIndex id);
    void addNewRecipe(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &pic);

    void on_bestButton_clicked();
    void on_deleteButton_clicked();
    void on_edit_bestButton_clicked();

    void categoriesAllButton_selected();
    void categoriesFirstButton_selected();
    void categoriesSecondButton_selected();
    void categoriesGarnishButton_selected();
    void categoriesSalatButton_selected();
    void categoriesSauceButton_selected();
    void categoriesDrinkButton_selected();
    void categoriesMarinadeButton_selected();
    void categoriesStockButton_selected();
    void categoriesDoughButton_selected();
    void categoriesSnackButton_selected();
    void categoriesSweetButton_selected();


    void on_editButton_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;

    Dialog *confirmDeleteDialog;
    NewRecordWidget *newRecord;

    database dataControl;

    QSqlTableModel *recipesModel;

    QMenu *categoriesMenu;

    QAction *categoryAll;
    QAction *categoryFirst;
    QAction *categorySecond;
    QAction *categoryGarnish;
    QAction *categorySalat;
    QAction *categorySauce;
    QAction *categoryDrink;
    QAction *categoryMarinade;
    QAction *categoryStock;
    QAction *categoryDough;
    QAction *categorySnack;
    QAction *categorySweet;

    int currentID;
    QString currentCategory;

    int picLabel_width;
    int picLabel_height;

    QPixmap recipePic;

    bool flag_best;

    void categorySelected();

};
#endif // MAINWINDOW_H
