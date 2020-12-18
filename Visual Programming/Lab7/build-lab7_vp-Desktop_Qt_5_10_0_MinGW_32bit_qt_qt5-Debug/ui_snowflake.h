/********************************************************************************
** Form generated from reading UI file 'snowflake.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNOWFLAKE_H
#define UI_SNOWFLAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snowflake
{
public:

    void setupUi(QWidget *snowflake)
    {
        if (snowflake->objectName().isEmpty())
            snowflake->setObjectName(QStringLiteral("snowflake"));
        snowflake->resize(400, 300);

        retranslateUi(snowflake);

        QMetaObject::connectSlotsByName(snowflake);
    } // setupUi

    void retranslateUi(QWidget *snowflake)
    {
        snowflake->setWindowTitle(QApplication::translate("snowflake", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snowflake: public Ui_snowflake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNOWFLAKE_H
