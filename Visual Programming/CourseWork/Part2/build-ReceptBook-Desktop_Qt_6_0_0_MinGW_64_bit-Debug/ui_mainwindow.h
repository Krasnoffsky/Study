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
#include <QtGui/QIcon>
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
    QLineEdit *nameLabel;
    QPushButton *filterButton;
    QPushButton *helpButton;

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
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow {background-color: rgb(142, 154, 76)}\n"
"QPushButton {background-color: rgb(207, 211, 126);\n"
"	border-width: 0px;}\n"
"QLineEdit {background-color: rgb(207, 211, 126)}\n"
"#nameEdit {border-radius: 20px;\n"
"	border-width: 1px;\n"
"	min-height: 40px;\n"
"	max-height: 40px;\n"
"	min-width: 220px;\n"
"	max-width: 220px}\n"
"#searchBox {\n"
"	border-radius: 15px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 250px;\n"
"	max-width: 250px;\n"
"	border-color: green }\n"
"#recipesTable  {background-color: rgb(207, 211, 126)}\n"
"#outputBox  {background-color: rgb(207, 211, 126)}\n"
"QMenu {background-color: rgb(207, 211, 126)}\n"
"\n"
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
        outputBox->setGeometry(QRect(550, 90, 631, 531));
        outputBox->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        outputBox->setReadOnly(true);
        categoriesButton = new QPushButton(centralwidget);
        categoriesButton->setObjectName(QString::fromUtf8("categoriesButton"));
        categoriesButton->setGeometry(QRect(30, 130, 200, 40));
        recipesTable = new QTableView(centralwidget);
        recipesTable->setObjectName(QString::fromUtf8("recipesTable"));
        recipesTable->setGeometry(QRect(30, 180, 200, 360));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(30, 550, 200, 40));
        edit_bestButton = new QPushButton(centralwidget);
        edit_bestButton->setObjectName(QString::fromUtf8("edit_bestButton"));
        edit_bestButton->setGeometry(QRect(300, 380, 220, 40));
        picLabel = new QLabel(centralwidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(300, 90, 220, 220));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(300, 430, 220, 40));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(300, 480, 220, 40));
        nameLabel = new QLineEdit(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(300, 330, 220, 40));
        nameLabel->setMinimumSize(QSize(220, 40));
        nameLabel->setMaximumSize(QSize(220, 40));
        nameLabel->setReadOnly(true);
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setGeometry(QRect(270, 10, 160, 30));
        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(880, 10, 160, 30));
        MainWindow->setCentralWidget(centralwidget);
        bestButton->raise();
        outputBox->raise();
        categoriesButton->raise();
        recipesTable->raise();
        addButton->raise();
        edit_bestButton->raise();
        picLabel->raise();
        editButton->raise();
        deleteButton->raise();
        nameLabel->raise();
        searchBox->raise();
        filterButton->raise();
        helpButton->raise();

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
        filterButton->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
