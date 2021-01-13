/********************************************************************************
** Form generated from reading UI file 'newrecordwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWRECORDWIDGET_H
#define UI_NEWRECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewRecordWidget
{
public:
    QLabel *picLabel;
    QLabel *nameLabel;
    QPushButton *addPicButton;
    QPushButton *selectCategoryButton;
    QTextEdit *textEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *NewRecordWidget)
    {
        if (NewRecordWidget->objectName().isEmpty())
            NewRecordWidget->setObjectName(QString::fromUtf8("NewRecordWidget"));
        NewRecordWidget->resize(900, 650);
        NewRecordWidget->setStyleSheet(QString::fromUtf8("#NewRecordWidget {background-color: blue}\n"
"QLabel {background-color: white}\n"
"QTextEdit {background-color: white}\n"
""));
        picLabel = new QLabel(NewRecordWidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(30, 20, 221, 201));
        nameLabel = new QLabel(NewRecordWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(30, 300, 221, 41));
        addPicButton = new QPushButton(NewRecordWidget);
        addPicButton->setObjectName(QString::fromUtf8("addPicButton"));
        addPicButton->setGeometry(QRect(30, 230, 221, 41));
        selectCategoryButton = new QPushButton(NewRecordWidget);
        selectCategoryButton->setObjectName(QString::fromUtf8("selectCategoryButton"));
        selectCategoryButton->setGeometry(QRect(30, 350, 221, 41));
        textEdit = new QTextEdit(NewRecordWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(280, 20, 601, 561));
        saveButton = new QPushButton(NewRecordWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(510, 600, 181, 41));
        cancelButton = new QPushButton(NewRecordWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(700, 600, 181, 41));

        retranslateUi(NewRecordWidget);

        QMetaObject::connectSlotsByName(NewRecordWidget);
    } // setupUi

    void retranslateUi(QWidget *NewRecordWidget)
    {
        NewRecordWidget->setWindowTitle(QCoreApplication::translate("NewRecordWidget", "Form", nullptr));
        picLabel->setText(QCoreApplication::translate("NewRecordWidget", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("NewRecordWidget", "TextLabel", nullptr));
        addPicButton->setText(QCoreApplication::translate("NewRecordWidget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        selectCategoryButton->setText(QCoreApplication::translate("NewRecordWidget", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        saveButton->setText(QCoreApplication::translate("NewRecordWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        cancelButton->setText(QCoreApplication::translate("NewRecordWidget", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewRecordWidget: public Ui_NewRecordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWRECORDWIDGET_H
