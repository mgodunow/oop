#include "triangle.h"
#include "QPointF"
#include "QPolygonF"

Triangle::Triangle(QPointF first_point, QPointF second_point, QPointF third_point) {
    a = first_point;
    b = second_point;
    c = third_point;
}

void Triangle::draw(QPainter* painter) {
    QPolygon polygon;
    polygon << a.toPoint() << b.toPoint() << c.toPoint();
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

void Triangle::setX(int x_cord) {
    int hx2 = b.x() - a.x();
    int hx3 = c.x() - a.x();
    a.setX(x_cord);
    b.setX(x_cord + hx2);
    c.setX(x_cord + hx3);
}

void Triangle::setY(int y_cord) {
    int cy = (a.y() + b.y() + c.y())/3;
    int hy2 = b.y() - a.y();
    int hy3 = c.y() - a.y();
    a.setY(y_cord - cy/3);
    b.setY(y_cord + hy2 - cy/3);
    c.setY(y_cord + hy3 - cy/3);
}
bool Triangle::isTaken() {
    return isTriangleTaken;
}

void Triangle::setTaken(bool t) {
    isTriangleTaken = t;
}
