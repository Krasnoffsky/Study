#include "docwindow_krasnov.h"
#include <QFileDialog>
#include <QTextStream>

DocWindow_Krasnov::DocWindow_Krasnov(QWidget *parent) : QTextEdit(parent)
{

}

void DocWindow_Krasnov::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if(str.isEmpty())
        return;
    QFile file(str);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        m_strFileName = str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindow_Krasnov::slotSaveAs()
{
    QString str = QFileDialog::getOpenFileName(0, m_strFileName);
    if(!str.isEmpty())
    {
        m_strFileName = str;
        slotSave();
    }
}

void DocWindow_Krasnov::slotSave()
{
    if(m_strFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }
    QFile file(m_strFileName);
    if(file.open(QIODevice::WriteOnly))
        QTextStream(&file) << toPlainText();
    file.close();
    emit changeWindowTitle(m_strFileName);
}

