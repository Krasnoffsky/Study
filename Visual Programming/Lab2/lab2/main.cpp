#include "startdialog_krasnov.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_KRASNOV startDialog;
    startDialog.show();

    return a.exec();
}
