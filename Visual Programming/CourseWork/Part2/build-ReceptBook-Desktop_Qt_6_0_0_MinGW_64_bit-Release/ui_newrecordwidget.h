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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewRecordWidget
{
public:
    QLabel *picLabel;
    QPushButton *addPicButton;
    QPushButton *selectCategoryButton;
    QTextEdit *recipeBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLineEdit *nameLine;
    QTextEdit *ingredientsBox;

    void setupUi(QWidget *NewRecordWidget)
    {
        if (NewRecordWidget->objectName().isEmpty())
            NewRecordWidget->setObjectName(QString::fromUtf8("NewRecordWidget"));
        NewRecordWidget->resize(900, 650);
        NewRecordWidget->setMinimumSize(QSize(900, 650));
        NewRecordWidget->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewRecordWidget->setWindowIcon(icon);
        NewRecordWidget->setStyleSheet(QString::fromUtf8("#NewRecordWidget {background-color: rgb(142, 154, 76)}\n"
"QPushButton {background-color: rgb(207, 211, 126);;\n"
"	border-width: 0px;}\n"
"QPushButton:hover {background-color: rgb(207, 240, 126);;\n"
"	border-width: 0px;}\n"
"QLineEdit {background-color: rgb(207, 211, 126)}\n"
"#nameLine {border-radius: 20px;\n"
"	border-width: 1px;\n"
"	min-height: 40px;\n"
"	max-height: 40px;\n"
"	min-width: 200px;\n"
"	max-width: 200px}\n"
"\n"
"QTextEdit  {background-color: rgb(207, 211, 126)}\n"
""));
        picLabel = new QLabel(NewRecordWidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(30, 20, 200, 200));
        addPicButton = new QPushButton(NewRecordWidget);
        addPicButton->setObjectName(QString::fromUtf8("addPicButton"));
        addPicButton->setGeometry(QRect(30, 230, 200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri Light"));
        font.setPointSize(11);
        addPicButton->setFont(font);
        selectCategoryButton = new QPushButton(NewRecordWidget);
        selectCategoryButton->setObjectName(QString::fromUtf8("selectCategoryButton"));
        selectCategoryButton->setGeometry(QRect(30, 350, 200, 40));
        selectCategoryButton->setFont(font);
        recipeBox = new QTextEdit(NewRecordWidget);
        recipeBox->setObjectName(QString::fromUtf8("recipeBox"));
        recipeBox->setGeometry(QRect(280, 230, 601, 351));
        recipeBox->setFont(font);
        saveButton = new QPushButton(NewRecordWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(510, 600, 180, 40));
        saveButton->setFont(font);
        cancelButton = new QPushButton(NewRecordWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(700, 600, 180, 40));
        cancelButton->setFont(font);
        nameLine = new QLineEdit(NewRecordWidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(30, 303, 200, 40));
        nameLine->setFont(font);
        ingredientsBox = new QTextEdit(NewRecordWidget);
        ingredientsBox->setObjectName(QString::fromUtf8("ingredientsBox"));
        ingredientsBox->setGeometry(QRect(280, 14, 600, 200));
        ingredientsBox->setFont(font);

        retranslateUi(NewRecordWidget);
        QObject::connect(cancelButton, &QPushButton::clicked, NewRecordWidget, &QWidget::close);

        QMetaObject::connectSlotsByName(NewRecordWidget);
    } // setupUi

    void retranslateUi(QWidget *NewRecordWidget)
    {
        NewRecordWidget->setWindowTitle(QCoreApplication::translate("NewRecordWidget", "\320\235\320\276\320\262\321\213\320\271 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        picLabel->setText(QString());
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
