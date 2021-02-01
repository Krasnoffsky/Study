#include "sdiprogram_krasnov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDIProgram_Krasnov w;
    w.show();

    return a.exec();
}
