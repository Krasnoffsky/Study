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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *bestButton;
    QLineEdit *searchBox;
    QTextEdit *outputBox;
    QPushButton *categoriesButton;
    QTableView *recipesTable;
    QPushButton *addButton;
    QPushButton *edit_bestButton;
    QLabel *picLabel;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLabel *nameLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
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
"	background-color: rgb(205, 249, 62)}\n"
"#searchBox {\n"
"	border-radius: 15px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 250px;\n"
"	max-width: 250px;\n"
"	border-color: green }\n"
"\n"
"QLabel { background-color: white}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bestButton = new QPushButton(centralwidget);
        bestButton->setObjectName(QString::fromUtf8("bestButton"));
        bestButton->setGeometry(QRect(1049, 10, 160, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri Light"));
        font.setPointSize(10);
        bestButton->setFont(font);
        bestButton->setCursor(QCursor(Qt::PointingHandCursor));
        searchBox = new QLineEdit(centralwidget);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setGeometry(QRect(10, 10, 250, 30));
        searchBox->setFont(font);
        searchBox->setCursor(QCursor(Qt::IBeamCursor));
        searchBox->setFrame(true);
        outputBox = new QTextEdit(centralwidget);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));
        outputBox->setEnabled(true);
        outputBox->setGeometry(QRect(570, 90, 631, 531));
        outputBox->setReadOnly(true);
        categoriesButton = new QPushButton(centralwidget);
        categoriesButton->setObjectName(QString::fromUtf8("categoriesButton"));
        categoriesButton->setGeometry(QRect(20, 100, 200, 40));
        recipesTable = new QTableView(centralwidget);
        recipesTable->setObjectName(QString::fromUtf8("recipesTable"));
        recipesTable->setGeometry(QRect(20, 150, 200, 360));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(20, 520, 200, 40));
        edit_bestButton = new QPushButton(centralwidget);
        edit_bestButton->setObjectName(QString::fromUtf8("edit_bestButton"));
        edit_bestButton->setGeometry(QRect(330, 380, 200, 40));
        picLabel = new QLabel(centralwidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(320, 90, 220, 220));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(330, 430, 200, 40));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(330, 480, 200, 40));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(320, 330, 220, 40));
        nameLabel->setCursor(QCursor(Qt::IBeamCursor));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Avocado", nullptr));
        bestButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        searchBox->setInputMask(QString());
        searchBox->setText(QString());
        categoriesButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        edit_bestButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        picLabel->setText(QString());
        editButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        nameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
