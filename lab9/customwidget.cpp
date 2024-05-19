#include "customwidget.h"
#include "ui_customwidget.h"

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "rectangle.h"
#include "QPointF"

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomWidget)
{
    list.emplace_back(new Circle(100, 100, 50));
    list.emplace_back(new Rectangle(230, 180, 100, 100));
    list.emplace_back(new Triangle(QPointF(500, 50), QPointF(410, 100), QPointF(560, 325)));
    ui->setupUi(this);
}

CustomWidget::~CustomWidget()
{
    delete ui;
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    QPainter painter(this);

    for(auto& l:list)
        l->draw(&painter);

    painter.end();
}

