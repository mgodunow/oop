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

enum engineType car::getEngineType() {
    return enginetype;
}

int car::getEnginePower() {
    return enginePower;
}

void car::setEngineType(int _engineType) {
    car::enginetype = static_cast<engineType>(_engineType);
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

void car::setEngineTypeString(QString et) {
    int num;
    if (et == "ICE") {
        num = 0;
    } else if (et == "Diesel") {
        num = 1;
    } else if (et == "Hybrid") {
        num = 2;
    } else if (et == "Electro") {
        num = 3;
        }

    enginetype = static_cast<engineType>(num);
}

bool car::operator ==(car c1) {
    if (enginePower != c1.getEnginePower() || brand != c1.getBrand() || model != c1.getModel()) {
        return false;
    }
    return true;
}

//friend std::ostream& car::operator << (std::ostream& os, car c1) {
// os << QString::number(c.getId()) << " " << c.getBrand() + " " << c.getModel() << " " + c.getEngineTypeString() << " "+ QString::number(c.getEnginePower()) << "\n";
// return os;
//}

car::~car() {

}
