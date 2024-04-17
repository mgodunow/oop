#include "csvwriter.h"
#include <fstream>

#include "car.h"

CSVWriter::CSVWriter()
{
}

bool CSVWriter::isOpen() {
    return fout.is_open();
}


void CSVWriter::writeAll(QString path, std::vector<car> cars) {
    std::ofstream fout(path.toStdString());
    if(fout.is_open())
        for (auto& c: cars){
            fout << c.getId() << "," << c.getBrand().toStdString() << "," << c.getModel().toStdString() << "," << c.getEngineType() << "," << c.getEnginePower() << "\n";

           }
    fout.close();
}
