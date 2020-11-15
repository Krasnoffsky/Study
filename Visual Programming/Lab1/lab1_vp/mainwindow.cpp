#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authors.h"
#include "ui_authors.h"
#include "QFileDialog"
#include "QTextDocumentWriter"
#include "QTextEdit"


void MainWindow::About_Lab1()
{
    authors *dg = new authors();
    dg->show();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action,SIGNAL(triggered()), this, SLOT(About_Lab1()));

    QAction *pactOpen = new QAction("file open action", 0);
    pactOpen->setText("&Открыть");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Окрытие документа");
    pactOpen->setStatusTip("Открыть файл");
    pactOpen->setWhatsThis("Открыть файл");
    pactOpen->setIcon(QPixmap("img3.jpg"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slot_open()));
    QMenu *pmuFile = new QMenu("Открыть");
    pmuFile->addAction(pactOpen);
    menuBar()->addMenu(pmuFile);

    QAction *pactSave = new QAction("file save action", 0);
    pactSave->setText("&Сохранить");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Сохранение содержимого textEdit");
    pactSave->setStatusTip("Сохранить файл");
    pactSave->setWhatsThis("Сохранить файл");
    pactOpen->setIcon(QPixmap("img3.jpg"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slot_save()));
    QMenu *pmuFile_save = new QMenu("Сохранить");
    pmuFile_save->addAction(pactSave);
    menuBar()->addMenu(pmuFile_save);

    QAction *pactClear = new QAction("textEdit clear", 0);
    pactClear->setText("&Очистить");
    pactClear->setShortcut(QKeySequence("CTRL+W"));
    pactClear->setToolTip("Очищаем textEdit");
    pactClear->setStatusTip("Очистить textEdit");
    pactClear->setWhatsThis("Очистить textEdit");
    pactOpen->setIcon(QPixmap("img3.jpg"));
    connect(pactClear, SIGNAL(triggered()), SLOT(slot_clear()));
    QMenu *pmuFile_clear = new QMenu("Очистить");
    pmuFile_clear->addAction(pactClear);
    menuBar()->addMenu(pmuFile_clear);

    ui->mainToolBar->addAction(pactOpen);
    ui->mainToolBar->addAction(pactSave);
    ui->mainToolBar->addAction(pactClear);
}

void MainWindow::slot_open()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", QDir::currentPath(), "*.cpp *.txt");
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) ui->textEdit->setPlainText(file.readAll());
}

void MainWindow::slot_save()
{
    QString filename = QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath(), "*.cpp *.txt");
    QTextDocumentWriter writer;
    writer.setFileName(filename);
    writer.write(ui->textEdit->document());
}

void MainWindow::slot_clear()
{
    ui->textEdit->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
