#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <krasnov.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    krasnov* myForm;
    QString name_for_send;

signals:
    void sendData(QString str);

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
