#include "csvreader.h"

#include <fstream>
#include <algorithm>
#include <QDebug>
#include <QFileDialog>

#include "car.h"

CSVReader::CSVReader()
{

}

std::vector<std::string> split_line(const std::string &str, char delim) {

   std::vector<std::string> tokens;

   if (!str.empty()) {
       size_t start = 0, end;
       do {
           tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
           end = str.find(delim, start);
           start = end + 1;
       } while (end != std::string::npos);
   }

   return tokens;
}

QString CSVReader::search() {
    QString filePath = QFileDialog::getOpenFileName(0, "Open File", "", "*.csv");
    QFile file(filePath);
    QString fileName = file.fileName().section("/", -1, -1);

    std::ifstream fin(fileName.toStdString());
    if(fin.is_open()){
        fin.close();
        return fileName;
     }

    fin.close();
    return "";
}

std::vector<car> CSVReader::readFile(QString path) {
    std::vector<car> cars;
    std::ifstream fin(path.toStdString());
    while(!fin.eof()) {
        std::string line;
        std::getline(fin, line);
        if(line == "") continue;
        auto tokens = split_line(line, ',');
        car c = {std::stoi(tokens[0]), QString::fromStdString(tokens[1]),
                 QString::fromStdString(tokens[2]), std::stoi(tokens[4])};
        c.setEngineType(std::stoi(tokens[3]));
        cars.push_back(c);
    }
    fin.close();
    return cars;
}
