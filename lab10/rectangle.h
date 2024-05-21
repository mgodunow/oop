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
    QString info();
private:
    int height;
    int width;
    int x;
    int y;
    bool isCursorInside;
};



#endif // RECTANGLE_H
