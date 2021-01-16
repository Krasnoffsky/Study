/********************************************************************************
** Form generated from reading UI file 'helper.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPER_H
#define UI_HELPER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Helper
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Helper)
    {
        if (Helper->objectName().isEmpty())
            Helper->setObjectName(QString::fromUtf8("Helper"));
        Helper->resize(900, 650);
        Helper->setMinimumSize(QSize(900, 650));
        Helper->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Helper->setWindowIcon(icon);
        Helper->setStyleSheet(QString::fromUtf8("QTextBrowser {background-color:  rgb(142, 154, 76)}"));
        textBrowser = new QTextBrowser(Helper);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 901, 651));

        retranslateUi(Helper);

        QMetaObject::connectSlotsByName(Helper);
    } // setupUi

    void retranslateUi(QWidget *Helper)
    {
        Helper->setWindowTitle(QCoreApplication::translate("Helper", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Helper: public Ui_Helper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPER_H
