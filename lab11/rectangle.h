#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QString>

class Rectangle: public Shape {
public:
    Rectangle(int x_cord, int y_cord, int h, int w);
    void draw(QPainter* painter);
    void updateIsCursorInside(QPoint &point);
    bool isInside();
    bool isTaken();
    void setTaken(bool t);
    void setX(int x_cord);
    void setY(int y_cord);
    QString info();
private:
    int height;
    int width;
    int x;
    int y;
    bool isRectTaken;
    bool isCursorInside;
};



#endif // RECTANGLE_H
