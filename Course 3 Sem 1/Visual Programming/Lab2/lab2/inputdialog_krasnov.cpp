#include "inputdialog_krasnov.h"
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QPushButton>

inputdialog::inputdialog(QWidget* pwgt) : QDialog(pwgt)
{
    m_ptxFirstName = new QLineEdit;
    m_ptxLastName = new QLineEdit;

    QLabel* plblFirstName = new QLabel("&Имя");
    QLabel* plblLastName = new QLabel("&Фамилия");

    plblFirstName->setBuddy(m_ptxFirstName);
    plblLastName->setBuddy(m_ptxLastName);

    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxLastName, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2, 0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

QString inputdialog::firstName() const
{
    return m_ptxFirstName->text();
}

QString inputdialog::lastName() const
{
    return m_ptxLastName->text();
}
