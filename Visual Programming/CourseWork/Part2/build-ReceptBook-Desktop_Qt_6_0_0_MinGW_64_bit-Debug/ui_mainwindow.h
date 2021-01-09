/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *bestButton;
    QLineEdit *searchBox;
    QPushButton *testButton;
    QTextEdit *textEdit;
    QPushButton *testButton2;
    QPushButton *testButton3;
    QLineEdit *nameLine;
    QTextEdit *ingredientsBox;
    QTextEdit *recipeBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1219, 636);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1219, 636));
        MainWindow->setMaximumSize(QSize(1219, 636));
        MainWindow->setMouseTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: blue}\n"
"#searchBox {\n"
"	border-radius: 15px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 150px;\n"
"	max-width: 150px;\n"
"	border-color: green }\n"
"#categories_label {\n"
"	background-color: green}\n"
"#control_label {\n"
"	background-color: rgb(100, 255, 17)}\n"
"#recept_label {\n"
"	background-color: rgb(255, 235, 19)}\n"
"#addButton {\n"
"	background: white;\n"
"	border-width:1px;\n"
"	border-radius:40px;\n"
"	max-width:80px;\n"
"	max-height:80px;\n"
"	min-width:80px;\n"
"	min-height:80px;}\n"
"QLabel {\n"
"background-color: red;\n"
"background: black}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bestButton = new QPushButton(centralwidget);
        bestButton->setObjectName(QString::fromUtf8("bestButton"));
        bestButton->setGeometry(QRect(1110, 10, 100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri Light"));
        font.setPointSize(10);
        bestButton->setFont(font);
        bestButton->setCursor(QCursor(Qt::PointingHandCursor));
        searchBox = new QLineEdit(centralwidget);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setGeometry(QRect(10, 10, 150, 30));
        searchBox->setFont(font);
        searchBox->setCursor(QCursor(Qt::IBeamCursor));
        searchBox->setFrame(true);
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(580, 80, 80, 25));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(660, 270, 541, 351));
        testButton2 = new QPushButton(centralwidget);
        testButton2->setObjectName(QString::fromUtf8("testButton2"));
        testButton2->setGeometry(QRect(580, 110, 80, 25));
        testButton3 = new QPushButton(centralwidget);
        testButton3->setObjectName(QString::fromUtf8("testButton3"));
        testButton3->setGeometry(QRect(580, 140, 80, 25));
        nameLine = new QLineEdit(centralwidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(10, 210, 251, 24));
        ingredientsBox = new QTextEdit(centralwidget);
        ingredientsBox->setObjectName(QString::fromUtf8("ingredientsBox"));
        ingredientsBox->setGeometry(QRect(10, 240, 251, 121));
        recipeBox = new QTextEdit(centralwidget);
        recipeBox->setObjectName(QString::fromUtf8("recipeBox"));
        recipeBox->setGeometry(QRect(10, 370, 251, 171));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Recipe Book", nullptr));
        bestButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        searchBox->setInputMask(QString());
        searchBox->setText(QString());
        testButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        testButton2->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        testButton3->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
