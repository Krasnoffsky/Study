#ifndef DOCWINDOW_KRASNOV_H
#define DOCWINDOW_KRASNOV_H

#include <QTextEdit>
#include <QString>

class DocWindow_Krasnov: public QTextEdit
{
private:
    QString m_strFileName;

public:
    DocWindow_Krasnov();
signals:
    void ChangeWindowTitle(const QString&);

public slots:
    SlotLoad();
    SlotSave();
    SlotSaveAs();
};

#endif // DOCWINDOW_KRASNOV_H
