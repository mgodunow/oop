#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include "car.h"

class AbstractReader{

public:
    virtual bool is_open() = 0;
    virtual std::vector<car> read() = 0;
};

#endif // ABSTRACTREADER_H
