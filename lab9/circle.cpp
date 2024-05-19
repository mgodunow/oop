#include "circle.h"

Circle::Circle(int x_cord, int y_cord, int r) {
    radius = r;
    x = x_cord;
    y = y_cord;
}

void Circle::draw(QPainter* painter) {
    painter -> drawEllipse(x, y, radius, radius);
}
