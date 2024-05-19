#include "rectangle.h"

Rectangle::Rectangle(int x_cord, int y_cord, int h, int w) {
    height = h;
    width = w;
    x = x_cord;
    y = y_cord;
}

void Rectangle::draw(QPainter* painter) {
    painter -> drawRect(x, y, height, width);
}
