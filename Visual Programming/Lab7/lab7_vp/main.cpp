#include "figures_krasnov.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    figures_krasnov window;

    window.resize(700, 700);
    window.setWindowTitle("Lab7_krasnov");
    window.show();

    return a.exec();
}
