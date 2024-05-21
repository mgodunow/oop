#include "customwidget.h"
#include "ui_customwidget.h"

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "rectangle.h"
#include "QPointF"
#include <QToolTip>

#include <QMenu>


CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomWidget)
{
    list.emplace_back(new Circle(100, 100, 50));
    list.emplace_back(new Rectangle(230, 180, 100, 100));
    list.emplace_back(new Triangle(QPointF(500, 50), QPointF(410, 100), QPointF(560, 325)));
    ui->setupUi(this);

    setMouseTracking(true);
}

CustomWidget::~CustomWidget()
{
    delete ui;
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    QPainter painter(this);

    for(auto& l:list) {
        l->draw(&painter);
    }
   painter.end();
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event){
    QPoint position = event->pos();
    for(auto& l:list) {
        l->updateIsCursorInside(position);
        if (l->isTaken() && l->isInside()) {
            l->setX(position.x());
            l->setY(position.y());
            update();
        }
    }
    update();
}

void CustomWidget::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        QPoint position = event->pos();
        for(auto& l:list) {
            l->updateIsCursorInside(position);
            if (!l->isTaken() && l->isInside()) {
                l->setTaken(true);
                update();
                return;
            }
            if (l->isTaken() && l->isInside()) {
                l->setTaken(false);
                update();
                return;
            }
        }
    }
    if (event->button() == Qt::RightButton) {
        QPoint position = event->pos();
        QMenu* menu = new QMenu(this);
        menu->addAction(new QAction("Remove"));

        QPointF point = event->globalPosition();

        for(auto& l:list) {
            l->updateIsCursorInside(position);
            if(l->isInside()){
                menu->popup(point.toPoint());
                connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(removeFigure(QAction*)));
            }
        }
    }
}

void CustomWidget::removeFigure(QAction*) {
    for (auto it = list.begin(); it != list.end(); ) {
        if ((*it)->isInside()) {
            it = list.erase(it);
        } else {
            ++it;
        }
    }
}
