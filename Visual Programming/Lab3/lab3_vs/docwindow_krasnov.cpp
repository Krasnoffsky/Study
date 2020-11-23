#include "docwindow_krasnov.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

DocWindow_Krasnov:: DocWindow_Krasnov(QWidget* pwgt): QTextEdit(pwgt)
{

}
void DocWindow_Krasnov:: SlotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()){
        return;
    }
    QFile file(str);
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        m_strFileName = str;
        emit ChangeWindowTitle(m_strFileName);
    }
}

void DocWindow_Krasnov::SlotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if (str.isEmpty()){
        m_strFileName = str;
        SlotSave();
    }

}

void DocWindow_Krasnov::SlotSave()
{
    if(m_strFileName.isEmpty()){
        SlotSaveAs();
        return;
    }

    QFile file(m_strFileName);
    if (file.open(QIODevice::WriteOnly)){
        QtextStream(&file)<<toPlainText();
    }
    file.close();
    emit ChangeWindowTitle(m_strFileName);
    QMessageBox msgSave;
    msgSave.setInformativeText("File successfully saved");
    msgSave.exec();

}
