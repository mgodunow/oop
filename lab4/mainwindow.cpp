#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtextbrowser.h"
#include <QFileDialog>
#include <QColor>

#include "car.h"
#include "csvreader.h"
#include "csvwriter.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->btnAdd->setStyleSheet("background-color:#243f40; color: white");
    ui->btnSave->setStyleSheet("background-color:#243f40; color: white");
    ui->btnSearch->setStyleSheet("background-color:#243f40; color: white");
    ui -> btnAddCar -> setStyleSheet("background-color:#243f40; color: white");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSearch_clicked(){
    QString text = CSVReader::search();
    if(text != ""){
        ui->textBrowser->appendGreen("File: " + text + "\n", ui->textBrowser );
        ui->linePath->setText(text);
        ui->btnAdd->setEnabled(true);
    } else {
        ui->textBrowser->appendRed("File error\n", ui->textBrowser );
        ui->btnAdd->setEnabled(false);
    }
}

void MainWindow::on_btnAdd_clicked(){
    auto carsFromFile = CSVReader::readFile(ui->linePath->text());
    for(auto& c:carsFromFile) {
        cars.push_back(c);
    }
    sortAndDraw();
}

void MainWindow::sortAndDraw() {
    std::sort(cars.begin(), cars.end(), [](car& lhs, car& rhs){return lhs.getEnginePower() > rhs.getEnginePower();});
    for(auto& c:cars){
        if (c.getEngineType() == 0 && c.getEnginePower() > 249)
        {
            draw(c);
        }
}
    ui->textBrowser->append("\n");
}

void MainWindow::draw(car c){
    ui->textBrowser->appendPink(QString::number(c.getId()) + " " + c.getBrand() + " " + c.getModel() + " " + c.getEngineTypeString()+ " "+ QString::number(c.getEnginePower()), ui->textBrowser);
}

void MainWindow::on_btnAddCar_clicked()
{
    ui -> textBrowser -> appendBlue("Successfully added a new car\n", ui->textBrowser);
    int id = ui->ID->text().toInt();
    QString brand = ui->brand->text();
    QString model = ui->model->text();
    int enginePower = ui->power->text().toInt();
    car c = {id, brand, model, enginePower};
    c.setEngineTypeString(ui->engineType->currentText());

    cars.push_back(c);
    sortAndDraw();

    ui->ID->clear();
    ui->brand->clear();
    ui->model->clear();
    ui->power->clear();
}
void MainWindow::on_btnSave_clicked()
{
    CSVWriter::writeAll(ui->savePath->text(), cars);
    ui->savePath->clear();
    ui -> textBrowser -> appendGreen("File successfully saved!\n", ui->textBrowser);
}

