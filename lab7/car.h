#include <QString>
#include "iostream"

#ifndef CAR_H
#define CAR_H

enum engineType{ICE, DIESEL, HYBRID, ELECTRO};

class car
{
private:

    int id;
    QString brand;
    QString model;
    int enginePower;
    enum engineType enginetype;
public:
    car(int id, QString brand, QString model, int enginePower);
    ~car();
    int getId();
    QString getBrand();
    QString getModel();
    engineType getEngineType();
    QString getEngineTypeString();
    void setEngineType(int engineType);
    void setEngineTypeString(QString _engineType);
    int getEnginePower();
    bool operator < (car c1) {return enginePower<c1.getEnginePower();}
    bool operator == (car c1);
    friend std::ostream& operator << (std::ostream& os,car c1) {
        os << c1.getId() << " " << c1.getBrand().toStdString() + " " << c1.getModel().toStdString() << " " + c1.getEngineTypeString().toStdString() << " " + c1.getEnginePower() << "\n";
        return os;
    }
};

#endif // CAR_H
