#ifndef INPUTDIALOG_KRASNOV_H
#define INPUTDIALOG_KRASNOV_H

#include <QDialog>
#include <QLineEdit>

class inputdialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit *m_ptxFirstName;
    QLineEdit *m_ptxLastName;
public:
    inputdialog(QWidget* pwgt = 0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_KRASNOV_H
