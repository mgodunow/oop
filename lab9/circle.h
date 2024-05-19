#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape {
public:
    Circle(int x_cord, int y_cord, int r);
    void draw(QPainter* painter);
private:
    int radius;
    int x;
    int y;
};

#endif // CIRCLE_H
