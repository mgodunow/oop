#include <fstream>
#include <algorithm>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);


}


MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_btnSearch_clicked(){
    QString text = Film::search();
    if(text != ""){
        ui->linePath->setText(text);
        ui->btnAddFile->setEnabled(true);
    } else {
        ui->linePath->setText("File error");
        ui->btnAddFile->setEnabled(false);
    }
}


void MainWindow::on_btnAddFile_clicked(){
     ui->textBrowser->clear();
     films = Film::readFile(ui->linePath->text());
     for(const auto& f:films){
         draw(f);
     }
}


void MainWindow::on_btnAdd_clicked(){
    int id = ui->lineID->text().toInt();
    QString name = ui->lineName->text();
    int year = ui->lineYear->text().toInt();
    Film f = {id, name, Film::setGenre(ui->cbGenre->currentText()), year};
    films.push_back(f);

    if(name.compare("") && year != 0)
        draw(f);

    ui->lineID->clear();
    ui->lineName->clear();
    ui->lineYear->clear();
}

void MainWindow::draw(Film f){
    ui->textBrowser->append(QString::number(f.getId()) + ";" + f.getName() + ";" + f.getGenreString() + ";" + QString::number(f.getYear()));
}

void MainWindow::on_btnSave_clicked(){
    Film::saveFile(ui->linePath_2->text(), films, ui->rbtCondition->isChecked());
}


void MainWindow::on_btnSort_clicked(){
    ui->textBrowser->clear();
    std::sort(films.begin(), films.end(), [](Film& lhs, Film& rhs){return lhs.getYear() > rhs.getYear();});
    for(const auto& f:films){
        draw(f);
    }
}

