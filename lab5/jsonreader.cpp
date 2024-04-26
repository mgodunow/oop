#include "jsonreader.h"

#include <iostream>
#include <QDebug>
#include <car.h>
#include <nlohmann/json.hpp>
#include <QString>

using Json = nlohmann::json;

JSONReader::JSONReader(QString path){
    fin.open(path.toStdString());
}

JSONReader::~JSONReader(){
    fin.close();
}

std::vector<car> JSONReader::read(){
    std::vector<car> cars;

    Json json;

    fin >> json;
    for(const auto & j: json) {
       car c = {j["id"], QString::fromStdString(j["brand"]),
                QString::fromStdString(j["model"]), j["engine-power"]};
       c.setEngineType(j["engine-type"]);
       cars.push_back(c);
    return cars;
}
}
