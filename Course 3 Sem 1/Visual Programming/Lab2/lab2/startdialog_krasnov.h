#ifndef STARTDIALOG_KRASNOV_H
#define STARTDIALOG_KRASNOV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_krasnov.h"

class StartDialog_KRASNOV : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_KRASNOV(QWidget* pwgt = 0) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        inputdialog* pInputDialog = new inputdialog;
        if(pInputDialog->exec() == QDialog::Accepted)
        {
            QMessageBox::information(0,
                                     "Ваша информация: ",
                                     "Имя: "
                                     + pInputDialog->firstName(),
                                     + "\nФамилия: "
                                     + pInputDialog->lastName()
                                     );
        }
        delete pInputDialog;
    }

};

#endif // STARTDIALOG_KRASNOV_H
