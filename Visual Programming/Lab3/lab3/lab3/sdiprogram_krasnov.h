#ifndef SDIPROGRAM_KRASNOV_H
#define SDIPROGRAM_KRASNOV_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindow_krasnov.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SDIProgram_Krasnov; }
QT_END_NAMESPACE

class SDIProgram_Krasnov : public QMainWindow
{
    Q_OBJECT

public:
    DocWindow_Krasnov* pdoc = new DocWindow_Krasnov;
    SDIProgram_Krasnov(QWidget *parent = nullptr)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");


        pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence("Ctrl+O"));
        pmnuFile->addAction("&Save", pdoc, SLOT(slotSave()), QKeySequence("Ctrl+S"));
        pmnuFile->addAction("&SaveAs", pdoc, SLOT(slotSaveAs()), QKeySequence("Ctrl+A"));
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("Ctrl+Q"));
        pmnuFile->addAction("&Color", this, SLOT(slotChangeColor()));
        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);
    }

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Илья Краснов\nИП-814");
    }
    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
    void slotChangeColor()
    {
        pdoc->setTextColor(QColorDialog::getColor());
    }
private:
    Ui::SDIProgram_Krasnov *ui;
};
#endif // SDIPROGRAM_KRASNOV_H
