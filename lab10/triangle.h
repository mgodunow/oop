#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QString>

class Triangle : public Shape{
public:
    Triangle(QPointF first_point, QPointF second_point, QPointF third_point);
    void draw(QPainter* painter);
    void updateIsCursorInside(QPoint &point);
    bool isInside();
    QString info();
private:
    QPointF a;
    QPointF b;
    QPointF c;
    bool isCursorInside;
};

#endif // TRIANGLE_H
