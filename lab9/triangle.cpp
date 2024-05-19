#include "triangle.h"
#include "QPointF"
#include "QPolygonF"

Triangle::Triangle(QPointF first_point, QPointF second_point, QPointF third_point) {
    a = first_point;
    b = second_point;
    c = third_point;
}

void Triangle::draw(QPainter* painter) {
    QPolygonF polygon;
    polygon << a << b << c;
    painter -> drawPolygon(polygon);
}
