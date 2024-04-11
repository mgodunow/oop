#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "film.h"

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
    void on_btnSearch_clicked();

    void on_btnAddFile_clicked();

    void on_btnAdd_clicked();



    void on_btnSave_clicked();

    void on_btnSort_clicked();

private:
    Ui::MainWindow *ui;

    void draw(Film f);

    std::vector<Film> films;
};
#endif // MAINWINDOW_H
