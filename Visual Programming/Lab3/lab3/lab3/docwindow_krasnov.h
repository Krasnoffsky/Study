#ifndef DOCWINDOW_KRASNOV_H
#define DOCWINDOW_KRASNOV_H

#include <QTextEdit>



class DocWindow_Krasnov : public QTextEdit
{
    Q_OBJECT

private:
    QString m_strFileName;

public:
    DocWindow_Krasnov(QWidget *parent = nullptr);

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};


#endif // DOCWINDOW_KRASNOV_H
