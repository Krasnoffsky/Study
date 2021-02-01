#ifndef KRASNOV_H
#define KRASNOV_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class krasnov;
}

class krasnov : public QWidget
{
    Q_OBJECT

public:
    explicit krasnov(QWidget *parent = 0);
    ~krasnov();

private:
    Ui::krasnov *ui;

public slots:
    void reciveData(QString str);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // KRASNOV_H
