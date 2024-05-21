#include "rectangle.h"

Rectangle::Rectangle(int x_cord, int y_cord, int h, int w) {
    height = h;
    width = w;
    x = x_cord;
    y = y_cord;
}

void Rectangle::draw(QPainter* painter) {
    if (!isCursorInside) {
        painter -> drawRect(x, y, height, width);
        return;
        }
    painter -> setBrush(Qt::blue);
    painter -> drawRect(x, y, height, width);
    painter -> setBrush(Qt::NoBrush);
}

void Rectangle::updateIsCursorInside(QPoint &point) {
    QRect rect(x,y,width,height);
    isCursorInside = rect.contains(point);
}

bool Rectangle::isInside() {
    return isCursorInside;
}

QString Rectangle::info() {
    return QString::fromStdString("Ractangle, coords: "
                                  + std::to_string(x) + " " +
                                  std::to_string(y) + ", height " +
                                  std::to_string(height) + ", width " +
                                  std::to_string(width));
}

void Rectangle::setX(int x_cord) {
    x = x_cord - x/4;
}

void Rectangle::setY(int y_cord) {
    y = y_cord - y/4;
}

bool Rectangle::isTaken() {
    return isRectTaken;
}

void Rectangle::setTaken(bool t) {
    isRectTaken = t;
}
