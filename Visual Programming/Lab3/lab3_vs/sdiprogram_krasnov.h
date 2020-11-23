#ifndef SDIPROGRAM_KRASNOV_H
#define SDIPROGRAM_KRASNOV_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindow_krasnov.h"

namespace Ui {
class SDIProgram_Krasnov;
}

class SDIProgram_Krasnov : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_Krasnov(QWidget *pwgt): QMainWindow(pwgt){
        QMenu *pmnuFile = new QMenu("&File");
        QMenu *pmnuHelp = new QMenu("&Help");
        DocWindow_Krasnov *pDoc = new DocWindow_Krasnov;
        pmnuFile->addAction("&Open", pDoc, SLOT(SlotLoad()), QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save", pDoc, SLOT(SlotSave()), QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save As", pDoc, SLOT(SlotSaveAs()), QKeySequence("CTRL+SHIFT+S"));
        pmnuFile->addAction("&Open", qApp, SLOT(quit()), QKeySequence("CTRL+Q"));
        pmnuHelp->addAction("&About", this, SLOT(SlotAbout()), Qt::Key_F1);

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuFile);

        setCentralWidget(pDoc);

        connect(pDoc, SIGNAL(ChangeWindowTitle(const QString&)), SLOT(SlotChangeWindowTitle(const QString&)));

        statusBar()->showMessage("Ready", 2000);

    }

public slots:
    void SlotAbout()
    {
        QMessageBox::about(this, "About", "Краснов Илья\nИП-814");
    }

    void SlotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

private:
    Ui::SDIProgram_Krasnov *ui;
};

#endif // SDIPROGRAM_KRASNOV_H
