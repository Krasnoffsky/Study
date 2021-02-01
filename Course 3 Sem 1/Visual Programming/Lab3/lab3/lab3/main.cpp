#include "sdiprogram_krasnov.h"

#include <QApplication>
#include <QtWidgets>

void loadModules(QSplashScreen *psplash)
{
    QTime time;
    time.start();
    for (int i = 0; i < 100; )
    {
        if(time.elapsed() > 40)
        {
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: "
                             + QString::number(i) + "%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::black
                             );
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("spiders.png"));
    splash.show();
    SDIProgram_Krasnov w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();
    return a.exec();
}
