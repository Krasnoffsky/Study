#ifndef ENDLESSCYCLE_H
#define ENDLESSCYCLE_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <QString>
#include <QImage>
#include <QMouseEvent>
#include <QCursor>

class endlesscycle
{
public:
    endlesscycle();
    int speed_x = 10, speed_y = 10, bufferNumberOBJ = 0;
    void setNewPos(int x, int y);
    bool collision(int x, int y, int wOBJ, int hOBJ, int n);
    int x_mouse = 100, y_mouse = 100, wMouse = 30, hMouse = 30, ObjectMinX, ObjectMaxX, ObjectMinY, ObjectMaxY, W, H;
    QRect rect[6] = {{0,0,500,20},
                     {0,0,20,500},
                     {480,0,20,500},
                     {0,480,500,20},
                     {250,250,100,100},
                     {x_mouse, y_mouse, wMouse, hMouse}};

public:
    void paint(QPainter *painter, QPaintEvent *event);

private:

    QString temp = "C:/Study/Visual Programming/Lab7/christmas_tree.png";
    QString temp2 = "C:/Study/Visual Programming/Lab7/snowflake.png";
    QImage mouse;
    QImage home;

    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    void drug();
    void move();
};

#endif // ENDLESSCYCLE_H
