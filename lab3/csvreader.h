#include "car.h"

#ifndef CSVREADER_H
#define CSVREADER_H


class CSVReader
{
public:
    CSVReader();
    ~CSVReader();

    static QString search();
    static std::vector<car> readFile(QString path);
};

#endif // CSVREADER_H
