#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QString>

class Circle: public Shape {
public:
    Circle(int x_cord, int y_cord, int r);
    void draw(QPainter* painter);
    void updateIsCursorInside(QPoint &point);
    bool isInside();
    QString info();
private:
    int radius;
    int x;
    int y;
    bool isCursorInside;
};

#endif // CIRCLE_H
