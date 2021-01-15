#include "mainwindow.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QtWidgets>

void loadModules(QSplashScreen *psplash)
{

    for (int i = 0; i < 100; i++ )
    {
        psplash->showMessage("Loading modules: "
                             + QString::number(i) + "%",
                             Qt::AlignCenter|Qt::AlignBottom,
                             QColor(163,185,90)
                             );
        qApp->processEvents();
        Sleep(40);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen splash(QPixmap("C:\\Study\\Visual Programming\\CourseWork\\Part2\\ReceptBook\\avocado.png"));
    splash.show();
    w.setWindowTitle("Avocado");
    loadModules(&splash);
    splash.finish(&w);

    w.show();
    return a.exec();
}
