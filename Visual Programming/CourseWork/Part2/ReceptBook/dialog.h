#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT


public:
    Dialog(QWidget* pwgt = 0);

    QString firstName() const;
    QString lastName() const;
};

#endif // DIALOG_H
