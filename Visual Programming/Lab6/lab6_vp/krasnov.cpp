#include "krasnov.h"
#include "ui_krasnov.h"
#include "QFile"
#include "QTextDocumentWriter"
#include "QFileDialog"
#include "mainwindow.h"

krasnov::krasnov(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::krasnov)
{
    ui->setupUi(this);
}

krasnov::~krasnov()
{
    delete ui;
}

void krasnov::reciveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(1) + "\n" + lst.at(0));
    if (lst.size() > 1) {
        QImage image1(lst.at(0));
        ui->label->setPixmap(QPixmap::fromImage(image1));
    }
}

void krasnov::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Open"){
        QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", QDir::currentPath(), "*.txt");
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) ui->textEdit->setPlainText(file.readAll());
        QStringList inf = ui->textEdit->toPlainText().split("\n");
        QImage image2(inf.at(5));
        ui->label->setPixmap(QPixmap::fromImage(image2));
    }
    else if (button->text() == "Save") {
        QString filename = QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath(), "*.txt");
        QTextDocumentWriter writer;
        writer.setFileName(filename);
        writer.write(ui->textEdit->document());
    }
    else if (button->text() == "Reset"){
        ui->textEdit->clear();
        ui->label->clear();
    }
}
