/********************************************************************************
** Form generated from reading UI file 'authors.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORS_H
#define UI_AUTHORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_authors
{
public:
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *authors)
    {
        if (authors->objectName().isEmpty())
            authors->setObjectName(QStringLiteral("authors"));
        authors->resize(400, 300);
        label = new QLabel(authors);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-770, -160, 1371, 761));
        label->setPixmap(QPixmap(QString::fromUtf8("../img2.jpg")));
        textEdit = new QTextEdit(authors);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(150, 230, 104, 51));

        retranslateUi(authors);

        QMetaObject::connectSlotsByName(authors);
    } // setupUi

    void retranslateUi(QDialog *authors)
    {
        authors->setWindowTitle(QApplication::translate("authors", "Dialog", nullptr));
        label->setText(QString());
        textEdit->setHtml(QApplication::translate("authors", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\321\200\320\260\321\201\320\275\320\276\320\262<br />\320\230\320\273\321\214\321\217</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authors: public Ui_authors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORS_H
