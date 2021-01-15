#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QDialog>
#include <QMainWindow>
#include <QMenu>
#include <QSqlTableModel>
#include <QMessageBox>
#include "database.h"
#include "newrecordwidget.h"
#include "editrecordwidget.h"

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
    void addNewRecipe(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);
    void editOldRecipe(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);

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

    void filterAll_selected();
    void filterName_selected();
    void filterIngredients_selected();
    void filterRecipe_selected();


    void on_editButton_clicked();

    void on_addButton_clicked();


    void on_searchBox_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    NewRecordWidget *newRecord;
    EditRecordWidget *editRecord;

    database dataControl;

    QSqlTableModel *recipesModel;

    QMenu *categoriesMenu;
    QMenu *filtersMenu;

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

    QAction *filterAll;
    QAction *filterName;
    QAction *filterIngredients;
    QAction *filterRecipe;

    int currentID;
    int currentRow;
    QString currentCategory;
    QString currentPic;
    QString currentFilter;

    int picLabel_width;
    int picLabel_height;

    QByteArray recipePic;

    bool flag_best;

    void categorySelected();

signals:
    void sendForEdit(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);

};
#endif // MAINWINDOW_H
