#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QString>


class Shape
{
public:
    virtual void draw(QPainter* painter) = 0;
    virtual void updateIsCursorInside(QPoint &point) = 0;
    virtual bool isInside() = 0;
    virtual QString info() = 0;
    virtual bool isTaken() = 0;
    virtual void setTaken(bool t) = 0;
    virtual void setX(int x_cord) = 0;
    virtual void setY(int y_cord) = 0;
private:
};

#endif // SHAPE_H
