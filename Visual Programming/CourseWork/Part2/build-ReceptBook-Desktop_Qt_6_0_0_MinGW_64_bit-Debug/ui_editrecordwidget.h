/********************************************************************************
** Form generated from reading UI file 'editrecordwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRECORDWIDGET_H
#define UI_EDITRECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditRecordWidget
{
public:
    QPushButton *cancelButton;
    QLabel *picLabel;
    QPushButton *saveButton;
    QTextEdit *ingredientsBox;
    QLineEdit *nameLine;
    QTextEdit *recipeBox;
    QPushButton *selectCategoryButton;
    QPushButton *addPicButton;

    void setupUi(QWidget *EditRecordWidget)
    {
        if (EditRecordWidget->objectName().isEmpty())
            EditRecordWidget->setObjectName(QString::fromUtf8("EditRecordWidget"));
        EditRecordWidget->resize(900, 650);
        EditRecordWidget->setMinimumSize(QSize(900, 650));
        EditRecordWidget->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditRecordWidget->setWindowIcon(icon);
        cancelButton = new QPushButton(EditRecordWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(700, 606, 180, 40));
        picLabel = new QLabel(EditRecordWidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(30, 26, 200, 200));
        saveButton = new QPushButton(EditRecordWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(510, 606, 180, 40));
        ingredientsBox = new QTextEdit(EditRecordWidget);
        ingredientsBox->setObjectName(QString::fromUtf8("ingredientsBox"));
        ingredientsBox->setGeometry(QRect(280, 20, 600, 200));
        nameLine = new QLineEdit(EditRecordWidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(30, 309, 200, 40));
        recipeBox = new QTextEdit(EditRecordWidget);
        recipeBox->setObjectName(QString::fromUtf8("recipeBox"));
        recipeBox->setGeometry(QRect(280, 236, 601, 351));
        selectCategoryButton = new QPushButton(EditRecordWidget);
        selectCategoryButton->setObjectName(QString::fromUtf8("selectCategoryButton"));
        selectCategoryButton->setGeometry(QRect(30, 356, 200, 40));
        addPicButton = new QPushButton(EditRecordWidget);
        addPicButton->setObjectName(QString::fromUtf8("addPicButton"));
        addPicButton->setGeometry(QRect(30, 236, 200, 40));

        retranslateUi(EditRecordWidget);

        QMetaObject::connectSlotsByName(EditRecordWidget);
    } // setupUi

    void retranslateUi(QWidget *EditRecordWidget)
    {
        EditRecordWidget->setWindowTitle(QCoreApplication::translate("EditRecordWidget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditRecordWidget", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        picLabel->setText(QString());
        saveButton->setText(QCoreApplication::translate("EditRecordWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        selectCategoryButton->setText(QCoreApplication::translate("EditRecordWidget", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        addPicButton->setText(QCoreApplication::translate("EditRecordWidget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRecordWidget: public Ui_EditRecordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRECORDWIDGET_H
