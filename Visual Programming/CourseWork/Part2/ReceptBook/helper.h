#ifndef HELPER_H
#define HELPER_H

#include <QWidget>
#include <QFile>
#include <QObject>

namespace Ui {
class Helper;
}

class Helper : public QWidget
{
    Q_OBJECT

public:
    explicit Helper(QWidget *parent = nullptr);
    ~Helper();

private slots:
    void onAnchorClicked(const QUrl &link);

private:
    Ui::Helper *ui;
};

#endif // HELPER_H
