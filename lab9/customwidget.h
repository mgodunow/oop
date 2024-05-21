#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include "list"
#include "shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CustomWidget; }
QT_END_NAMESPACE

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();
    void paintEvent(QPaintEvent *event);

private:
    Ui::CustomWidget *ui;
    std::list<std::unique_ptr<Shape>> list;
};
#endif // CUSTOMWIDGET_H