#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "car.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

private:
    Ui::MainWindow *ui;

    void draw(car c);

    std::vector<car> cars;
};
#endif // MAINWINDOW_H
