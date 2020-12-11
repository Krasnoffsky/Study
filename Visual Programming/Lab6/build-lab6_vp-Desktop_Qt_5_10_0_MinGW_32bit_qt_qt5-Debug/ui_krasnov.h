/********************************************************************************
** Form generated from reading UI file 'krasnov.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KRASNOV_H
#define UI_KRASNOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
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
            krasnov->setObjectName(QStringLiteral("krasnov"));
        krasnov->resize(423, 465);
        label = new QLabel(krasnov);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 91, 111));
        textEdit = new QTextEdit(krasnov);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(170, 30, 241, 281));
        buttonBox = new QDialogButtonBox(krasnov);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 370, 251, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);

        retranslateUi(krasnov);

        QMetaObject::connectSlotsByName(krasnov);
    } // setupUi

    void retranslateUi(QWidget *krasnov)
    {
        krasnov->setWindowTitle(QApplication::translate("krasnov", "Form", nullptr));
        label->setText(QApplication::translate("krasnov", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class krasnov: public Ui_krasnov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KRASNOV_H
