#include "sdiprogram_krasnov.h"
#include "ui_sdiprogram_krasnov.h"

SDIProgram_Krasnov::SDIProgram_Krasnov(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SDIProgram_Krasnov)
{
    ui->setupUi(this);
}

SDIProgram_Krasnov::~SDIProgram_Krasnov()
{
    delete ui;
}
