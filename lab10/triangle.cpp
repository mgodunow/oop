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
    if (!isCursorInside) {
        painter -> drawPolygon(polygon);
        return;
        }
    painter -> setBrush(Qt::black);
    painter -> drawPolygon(polygon);
    painter -> setBrush(Qt::NoBrush);
}

void Triangle::updateIsCursorInside(QPoint &point) {
    QPolygon polygon;
    polygon << a.toPoint() << b.toPoint() << c.toPoint();
    isCursorInside = polygon.containsPoint(point, Qt::OddEvenFill);
}
bool Triangle::isInside() {
    return isCursorInside;
}

std::string pointfString(QPointF point) {
    return "x: " + std::to_string(point.x()) + " y: " + std::to_string(point.y());
}

QString Triangle::info() {
    return QString::fromStdString("Triangle with points" +
                                  std::string(" a: ") + pointfString(a) +
                                  std::string(" b: ") + pointfString(b) +
                                  std::string(" c: ")+ pointfString(c));
}

