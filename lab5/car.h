#include <QString>

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
};

#endif // CAR_H
