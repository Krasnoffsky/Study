/********************************************************************************
** Form generated from reading UI file 'sdiprogram_krasnov.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAM_KRASNOV_H
#define UI_SDIPROGRAM_KRASNOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgram_Krasnov
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDIProgram_Krasnov)
    {
        if (SDIProgram_Krasnov->objectName().isEmpty())
            SDIProgram_Krasnov->setObjectName(QStringLiteral("SDIProgram_Krasnov"));
        SDIProgram_Krasnov->resize(400, 300);
        menuBar = new QMenuBar(SDIProgram_Krasnov);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SDIProgram_Krasnov->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDIProgram_Krasnov);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SDIProgram_Krasnov->addToolBar(mainToolBar);
        centralWidget = new QWidget(SDIProgram_Krasnov);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SDIProgram_Krasnov->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SDIProgram_Krasnov);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SDIProgram_Krasnov->setStatusBar(statusBar);

        retranslateUi(SDIProgram_Krasnov);

        QMetaObject::connectSlotsByName(SDIProgram_Krasnov);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgram_Krasnov)
    {
        SDIProgram_Krasnov->setWindowTitle(QApplication::translate("SDIProgram_Krasnov", "SDIProgram_Krasnov", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDIProgram_Krasnov: public Ui_SDIProgram_Krasnov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAM_KRASNOV_H
