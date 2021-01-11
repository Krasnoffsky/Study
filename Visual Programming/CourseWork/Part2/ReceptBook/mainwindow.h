#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void writeFromDatabase(const QString name, const QString ingredients, const QString recipe, const QString type, const QString best);


private:
    Ui::MainWindow *ui;
    database dataControl;

};
#endif // MAINWINDOW_H
