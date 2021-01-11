#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void writeFromDatabase(const int id, const QString name, const QString ingredients, const QString recipe, const QString type, const QString best);


private slots:
    void on_bestButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    database dataControl;

    QSqlTableModel *recipesModel;

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

};
#endif // MAINWINDOW_H
