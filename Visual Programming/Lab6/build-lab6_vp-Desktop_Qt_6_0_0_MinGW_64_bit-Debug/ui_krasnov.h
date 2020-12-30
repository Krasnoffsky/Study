/********************************************************************************
** Form generated from reading UI file 'krasnov.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KRASNOV_H
#define UI_KRASNOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_krasnov
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *krasnov)
    {
        if (krasnov->objectName().isEmpty())
            krasnov->setObjectName(QString::fromUtf8("krasnov"));
        krasnov->resize(423, 465);
        label = new QLabel(krasnov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 91, 111));
        textEdit = new QTextEdit(krasnov);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(170, 30, 241, 281));
        buttonBox = new QDialogButtonBox(krasnov);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 370, 251, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);

        retranslateUi(krasnov);

        QMetaObject::connectSlotsByName(krasnov);
    } // setupUi

    void retranslateUi(QWidget *krasnov)
    {
        krasnov->setWindowTitle(QCoreApplication::translate("krasnov", "Form", nullptr));
        label->setText(QCoreApplication::translate("krasnov", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class krasnov: public Ui_krasnov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KRASNOV_H
