#ifndef EDITRECORDWIDGET_H
#define EDITRECORDWIDGET_H

#include <QBuffer>
#include <QByteArray>
#include <QWidget>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

namespace Ui {
class EditRecordWidget;
}

class EditRecordWidget : public QWidget
{
    Q_OBJECT

public slots:
    void catchInfo(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);

public:
    explicit EditRecordWidget(QWidget *parent = nullptr);
    ~EditRecordWidget();

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

    void on_cancelButton_clicked();

private:

    int picLabel_width;
    int picLabel_height;

    int currentID;

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
    QByteArray picture;


private:
    Ui::EditRecordWidget *ui;

signals:
    void sendToWidgetUpdate(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);
};

#endif // EDITRECORDWIDGET_H
