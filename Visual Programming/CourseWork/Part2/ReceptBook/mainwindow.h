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

public slots:
    bool WriteFromDatabase(QVariantList &data);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_testButton_clicked();

    void on_testButton2_clicked();

private:
    Ui::MainWindow *ui;
    database *dataControl;

};
#endif // MAINWINDOW_H
