#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape{
public:
    Triangle(QPointF first_point, QPointF second_point, QPointF third_point);
    void draw(QPainter* painter);
private:
    QPointF a;
    QPointF b;
    QPointF c;
};

#endif // TRIANGLE_H
