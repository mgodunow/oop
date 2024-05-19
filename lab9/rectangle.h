#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape {
public:
    Rectangle(int x_cord, int y_cord, int h, int w);
    void draw(QPainter* painter);
private:
    int height;
    int width;
    int x;
    int y;
};

#endif // RECTANGLE_H
