#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtextbrowser.h"
#include <QFileDialog>
#include <QColor>
#include <string>

#include "car.h"
#include "csvreader.h"
#include "csvwriter.h"

#include "jsonreader.h"

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
    QString filePath = QFileDialog::getOpenFileName(0, "Open File", "", "*");
    QFile file(filePath);
    QString fileName = file.fileName().section("/", -1, -1);

    std::ifstream fin(fileName.toLatin1().data());
    if(fin.is_open()){
        fin.close();
    } else {
        fin.close();
        fileName =  "";
    }
    if(fileName != ""){
        ui->textBrowser->appendGreen("File: " + fileName + "\n", ui->textBrowser);
        ui->linePath->setText(fileName);
        ui->btnAdd->setEnabled(true);
    } else {
        ui->textBrowser->appendRed("File error\n", ui->textBrowser );
        ui->btnAdd->setEnabled(false);
    }
}

std::string get_ext (std::string st) {
    size_t pos = st.rfind('.');
    if (pos <= 0) return "";
    return st.substr(pos+1, std::string::npos);
}

void MainWindow::on_btnAdd_clicked(){
    std::vector<car> file_cars;
    JSONReader reader(ui->linePath->text());
    if(get_ext(((ui->linePath->text()).toStdString())) == "json"){
        file_cars = reader.read();
        cars.insert(cars.end(), file_cars.begin(), file_cars.end());
    } else if (get_ext((ui->linePath->text()).toStdString()) == "csv") {
        CSVReader reader(ui->linePath->text());
        file_cars = reader.read();
        cars.insert(cars.end(), file_cars.begin(), file_cars.end());
        reader.~CSVReader();
    } else {
        ui->textBrowser->appendRed("Unknown file extension", ui->textBrowser);
        return;
    }
    reader.~JSONReader();
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
    ui->textBrowser << (QString::number(c.getId()) + " " + c.getBrand() + " " + c.getModel() + " " + c.getEngineTypeString() + " " + QString::number(c.getEnginePower()));
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
