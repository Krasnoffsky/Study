#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myForm = new krasnov();
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(this, SIGNAL(sendData(QString)), myForm, SLOT(reciveData(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
//        ui->lineEdit_3->setText(filename);
    name_for_send = filename;
    QImage image1(filename);
    ui->label->setPixmap(QPixmap::fromImage(image1));
}

void MainWindow::on_pushButton_2_clicked()
{
    if( ui->lineEdit->text() != "" and
            ui->lineEdit_2->text() != "" and
            ui->dateEdit->text() != "" and
            ui->dateEdit_2->text() != "")
    {
        myForm->show();
        QString st = name_for_send + "*"
            + "ФИО: " + ui->lineEdit->text() + "\n"
            + "Дата рождения: " + ui->dateEdit->text() + "\n"
            + "Должность: " + ui->lineEdit_2->text()+ "\n"
            + "Любимая дата: " + ui->dateEdit_2->text();
        if (ui->radioButton->isChecked())
            st += "\nПол: Мужской";
      else
          st += "\nПол: Женский";
      emit sendData(st);
    }

}
