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
    QTextEdit *outputBox;
    QPushButton *testButton2;
    QPushButton *testButton3;
    QPushButton *firstButton;
    QPushButton *secondButton;
    QPushButton *granishButton;
    QPushButton *sweetButton;
    QPushButton *snackButton;
    QPushButton *drinkButtton;
    QPushButton *marinadeButton;
    QPushButton *doughButton;
    QPushButton *sauceButton;
    QPushButton *stockButton;
    QPushButton *salatButton;

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
"	background-color: rgb(205, 249, 62)}\n"
"#searchBox {\n"
"	border-radius: 15px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 250px;\n"
"	max-width: 250px;\n"
"	border-color: green }\n"
""));
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
        searchBox->setGeometry(QRect(10, 10, 250, 30));
        searchBox->setFont(font);
        searchBox->setCursor(QCursor(Qt::IBeamCursor));
        searchBox->setFrame(true);
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(350, 10, 80, 25));
        outputBox = new QTextEdit(centralwidget);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));
        outputBox->setGeometry(QRect(320, 70, 881, 551));
        testButton2 = new QPushButton(centralwidget);
        testButton2->setObjectName(QString::fromUtf8("testButton2"));
        testButton2->setGeometry(QRect(440, 10, 80, 25));
        testButton3 = new QPushButton(centralwidget);
        testButton3->setObjectName(QString::fromUtf8("testButton3"));
        testButton3->setGeometry(QRect(530, 10, 80, 25));
        firstButton = new QPushButton(centralwidget);
        firstButton->setObjectName(QString::fromUtf8("firstButton"));
        firstButton->setGeometry(QRect(10, 70, 201, 41));
        secondButton = new QPushButton(centralwidget);
        secondButton->setObjectName(QString::fromUtf8("secondButton"));
        secondButton->setGeometry(QRect(10, 110, 201, 41));
        granishButton = new QPushButton(centralwidget);
        granishButton->setObjectName(QString::fromUtf8("granishButton"));
        granishButton->setGeometry(QRect(10, 150, 201, 41));
        sweetButton = new QPushButton(centralwidget);
        sweetButton->setObjectName(QString::fromUtf8("sweetButton"));
        sweetButton->setGeometry(QRect(10, 310, 201, 41));
        snackButton = new QPushButton(centralwidget);
        snackButton->setObjectName(QString::fromUtf8("snackButton"));
        snackButton->setGeometry(QRect(10, 190, 201, 41));
        drinkButtton = new QPushButton(centralwidget);
        drinkButtton->setObjectName(QString::fromUtf8("drinkButtton"));
        drinkButtton->setGeometry(QRect(10, 270, 201, 41));
        marinadeButton = new QPushButton(centralwidget);
        marinadeButton->setObjectName(QString::fromUtf8("marinadeButton"));
        marinadeButton->setGeometry(QRect(10, 430, 201, 41));
        doughButton = new QPushButton(centralwidget);
        doughButton->setObjectName(QString::fromUtf8("doughButton"));
        doughButton->setGeometry(QRect(10, 350, 201, 41));
        sauceButton = new QPushButton(centralwidget);
        sauceButton->setObjectName(QString::fromUtf8("sauceButton"));
        sauceButton->setGeometry(QRect(10, 390, 201, 41));
        stockButton = new QPushButton(centralwidget);
        stockButton->setObjectName(QString::fromUtf8("stockButton"));
        stockButton->setGeometry(QRect(10, 470, 201, 41));
        salatButton = new QPushButton(centralwidget);
        salatButton->setObjectName(QString::fromUtf8("salatButton"));
        salatButton->setGeometry(QRect(10, 230, 201, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Avocado", nullptr));
        bestButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        searchBox->setInputMask(QString());
        searchBox->setText(QString());
        testButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        testButton2->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        testButton3->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        firstButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\276\320\265 \320\261\320\273\321\216\320\264\320\276", nullptr));
        secondButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\320\265 \320\261\320\273\321\216\320\264\320\276", nullptr));
        granishButton->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\321\200\320\275\320\270\321\200", nullptr));
        sweetButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\260\320\264\320\276\321\201\321\202\320\270", nullptr));
        snackButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\203\321\201\320\272\320\270", nullptr));
        drinkButtton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\320\270\321\202\320\272\320\270", nullptr));
        marinadeButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\270\320\275\320\260\320\264\321\213", nullptr));
        doughButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\264\320\265\320\273\320\270\321\217 \320\270\320\267 \321\202\320\265\321\201\321\202\320\260", nullptr));
        sauceButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\203\321\201\321\213", nullptr));
        stockButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\321\202\320\276\320\262\320\272\320\270", nullptr));
        salatButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\260\320\273\320\260\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
