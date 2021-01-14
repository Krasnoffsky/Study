#ifndef NEWRECORDWIDGET_H
#define NEWRECORDWIDGET_H

#include <QBuffer>
#include <QWidget>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

namespace Ui {
class NewRecordWidget;
}

class NewRecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewRecordWidget(QWidget *parent = nullptr);
    ~NewRecordWidget();

private slots:
    void on_addPicButton_clicked();

    void categoriesFirstButton_selected();
    void categoriesSecondButton_selected();
    void categoriesGarnishButton_selected();
    void categoriesSalatButton_selected();
    void categoriesSauceButton_selected();
    void categoriesDrinkButton_selected();
    void categoriesMarinadeButton_selected();
    void categoriesStockButton_selected();
    void categoriesDoughButton_selected();
    void categoriesSnackButton_selected();
    void categoriesSweetButton_selected();

    void on_saveButton_clicked();

private:
    Ui::NewRecordWidget *ui;

    int picLabel_width;
    int picLabel_height;

    QMenu *categoriesMenu;

    QAction *categoryFirst;
    QAction *categorySecond;
    QAction *categoryGarnish;
    QAction *categorySalat;
    QAction *categorySauce;
    QAction *categoryDrink;
    QAction *categoryMarinade;
    QAction *categoryStock;
    QAction *categoryDough;
    QAction *categorySnack;
    QAction *categorySweet;

    QString currentCategory;
    QString currentPic;

signals:
    void sendToWidget(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);

};

#endif // NEWRECORDWIDGET_H
