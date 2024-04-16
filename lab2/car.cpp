#include "car.h"

car::car(int Id, QString Brand, QString Model, int EnginePower) {
    id = Id;
    brand = Brand;
    model = Model;
    enginePower = EnginePower;
}

int car::getId() {
    return id;
}

QString car::getBrand() {
    return brand;
}

QString car::getModel() {
    return model;
}

enum car::engineType car::getEngineType() {
    return enginetype;
}

int car::getEnginePower() {
    return enginePower;
}

void car::setEngineType(int engineType) {
    engineType = static_cast<car::engineType>(engineType);
}

QString car::getEngineTypeString() {
    int num = enginetype;
    QString str;
    switch (num) {
    case 0:
        str = "ICE";
    break;
    case 1:
        str = "Diesel";
    break;
    case 2:
        str = "Hybrid";
    break;
    case 3:
        str = "Electro";
    break;
    }
    return str;
}

car::~car() {

}
