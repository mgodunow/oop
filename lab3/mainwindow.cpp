#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "car.h"
#include "csvreader.h"
#include "csvwriter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnAdd->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSearch_clicked(){
    QString text = CSVReader::search();
    if(text != ""){
        ui->linePath->setText(text);
        ui->btnAdd->setEnabled(true);
    } else {
        ui->linePath->setText("file error");
        ui->btnAdd->setEnabled(false);
    }
}

void MainWindow::on_btnAdd_clicked(){
    ui->textBrowser->clear();
    auto carsFromFile = CSVReader::readFile(ui->linePath->text());
    for(auto& c:carsFromFile) {
        cars.push_back(c);
    }
    sortAndDraw(cars);
}

void MainWindow::sortAndDraw(std::vector<car> cars) {
    ui->textBrowser->clear();
    std::sort(cars.begin(), cars.end(), [](car& lhs, car& rhs){return lhs.getEnginePower() > rhs.getEnginePower();});
    for(auto& c:cars){
        if (c.getEngineType() == 0 && c.getEnginePower() > 249)
        {
            draw(c);
        }
}
}

void MainWindow::draw(car c){
    ui->textBrowser->append(QString::number(c.getId()) + " " + c.getBrand() + " " + c.getModel() + " " + c.getEngineTypeString()+ " "+ QString::number(c.getEnginePower()));
}

void MainWindow::on_btnAddCar_clicked()
{
    int id = ui->ID->text().toInt();
    QString brand = ui->brand->text();
    QString model = ui->model->text();
    int enginePower = ui->power->text().toInt();
    car c = {id, brand, model, enginePower};
    c.setEngineTypeString(ui->engineType->currentText());

    cars.push_back(c);
    sortAndDraw(cars);

    ui->ID->clear();
    ui->brand->clear();
    ui->model->clear();
    ui->power->clear();
}
void MainWindow::on_btnSave_clicked()
{
    CSVWriter::writeAll(ui->savePath->text(), cars);
    ui->savePath->clear();
}

