#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"

#include <vector>
#include <fstream>
#include <QString>
#include <car.h>

class JSONReader : public AbstractReader {
public:
    JSONReader(QString path);
    ~JSONReader();

    std::vector<car> read() override;
    bool is_open() override { return fin.is_open(); }
private:
    std::fstream fin;
};

#endif // JSONREADER_H
