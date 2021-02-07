/********************************************************************************
** Form generated from reading UI file 'tree.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREE_H
#define UI_TREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tree
{
public:

    void setupUi(QWidget *tree)
    {
        if (tree->objectName().isEmpty())
            tree->setObjectName(QString::fromUtf8("tree"));
        tree->resize(400, 300);

        retranslateUi(tree);

        QMetaObject::connectSlotsByName(tree);
    } // setupUi

    void retranslateUi(QWidget *tree)
    {
        tree->setWindowTitle(QCoreApplication::translate("tree", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tree: public Ui_tree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREE_H
