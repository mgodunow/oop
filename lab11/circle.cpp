#include "circle.h"
#include <cmath>

Circle::Circle(int x_cord, int y_cord, int r) {
    radius = r;
    x = x_cord;
    y = y_cord;
}

void Circle::draw(QPainter* painter) {
    QPoint center(x,y);
    if (!isCursorInside) {
       painter -> drawEllipse(center,radius, radius);
       return;
    }
    painter -> setBrush(Qt::green);
    painter -> drawEllipse(center,radius, radius);
    painter -> setBrush(Qt::NoBrush);
}

int square(int x) {
    return x * x;
}

double squareRoot(double x) {
    return sqrt(x);
}

bool isPointInCircle(int x, int y, int radius, int centerX, int centerY) {
    int distance = sqrt(pow((x - centerX), 2) + pow((y - centerY), 2));
    if (distance <= radius) {
        return true;
    } else {
        return false;
    }
}


void Circle::updateIsCursorInside(QPoint &point) {
    isCursorInside = isPointInCircle(point.x(), point.y(), radius, x, y);
}

bool Circle::isInside() {
    return isCursorInside;
}

QString Circle::info() {
    return QString::fromStdString("Circle with center in " +
                                  std::to_string(x) + " " +
                                  std::to_string(y) + " and radius " +
                                  std::to_string(radius));
}

void Circle::setX(int x_cord) {
    x = x_cord;
}

void Circle::setY(int y_cord) {
    y = y_cord;
}

bool Circle::isTaken() {
    return isCircleTaken;
}

void Circle::setTaken(bool t) {
    isCircleTaken = t;
}
