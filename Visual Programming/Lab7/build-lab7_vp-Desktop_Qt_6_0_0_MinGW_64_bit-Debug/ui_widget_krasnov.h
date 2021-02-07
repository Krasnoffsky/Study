/********************************************************************************
** Form generated from reading UI file 'widget_krasnov.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_KRASNOV_H
#define UI_WIDGET_KRASNOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_krasnov
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *widget_krasnov)
    {
        if (widget_krasnov->objectName().isEmpty())
            widget_krasnov->setObjectName(QString::fromUtf8("widget_krasnov"));
        widget_krasnov->resize(700, 700);
        graphicsView = new QGraphicsView(widget_krasnov);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, -9, 711, 711));

        retranslateUi(widget_krasnov);

        QMetaObject::connectSlotsByName(widget_krasnov);
    } // setupUi

    void retranslateUi(QWidget *widget_krasnov)
    {
        widget_krasnov->setWindowTitle(QCoreApplication::translate("widget_krasnov", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_krasnov: public Ui_widget_krasnov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_KRASNOV_H
