#ifndef NEWRECORDWIDGET_H
#define NEWRECORDWIDGET_H

#include <QWidget>

namespace Ui {
class NewRecordWidget;
}

class NewRecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewRecordWidget(QWidget *parent = nullptr);
    ~NewRecordWidget();

private:
    Ui::NewRecordWidget *ui;
};

#endif // NEWRECORDWIDGET_H
