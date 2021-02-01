#ifndef DOCWINDOW_KRASNOV_H
#define DOCWINDOW_KRASNOV_H

#include <QTextEdit>
#include <QString>

class DocWindow_Krasnov: public QTextEdit
{
private:
    QString m_strFileName;

public:
    DocWindow_Krasnov(QWidget* pwgt = 0);
signals:
    void ChangeWindowTitle(const QString&);

public slots:
    void SlotLoad();
    void SlotSave();
    void SlotSaveAs();
};

#endif // DOCWINDOW_KRASNOV_H
