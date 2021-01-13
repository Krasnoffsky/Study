#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    QPushButton* btnOk = new QPushButton("&Да");
    QPushButton* btnCancel = new QPushButton("&Нет");

    connect(btnOk, SIGNAL(clicked()), SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), SLOT(reject()));

    QLabel* message = new QLabel("Вы действительно хотите удалить запись?");
    QGridLayout* ptopLayout = new QGridLayout;

    ptopLayout->addWidget(message, 0, 0);
    ptopLayout->addWidget(btnOk, 1, 1);
    ptopLayout->addWidget(btnCancel, 1, 2);
    setLayout(ptopLayout);
}
