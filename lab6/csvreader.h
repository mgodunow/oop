#ifndef CSVREADER_H
#define CSVREADER_H

#include "abstractreader.h"

#include <vector>
#include <fstream>
#include <QString>
#include "car.h"

class CSVReader : public AbstractReader {
public:
    CSVReader(QString path);
    ~CSVReader();

    std::vector<car> read() override;
    bool is_open() override;

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
