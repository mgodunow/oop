#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "car.h"
#include <QString>
#include <fstream>


class CSVWriter
{
public:
  CSVWriter();
  ~CSVWriter();
  bool isOpen();
  static void writeAll(QString path, std::vector<car> cars);

private:
  std::ofstream fout;
};

#endif // CSVWRITER_H
