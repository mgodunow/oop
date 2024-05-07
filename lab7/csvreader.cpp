#include "csvreader.h"

#include <fstream>
#include <algorithm>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
#include "customexception.h"

#include "car.h"

CSVReader::CSVReader(QString path){
    fin.open(path.toStdString());
}

CSVReader::~CSVReader(){
    fin.close();
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

std::vector<car> CSVReader::read() {
    std::vector<car> cars;
    int lineNum;

    while(!fin.eof()) {
        try{
        lineNum++;
        std::string line;
        std::getline(fin, line);
        if(line == "") continue;
        auto tokens = split_line(line, ',');
        car c = {std::stoi(tokens[0]), QString::fromStdString(tokens[1]),
                 QString::fromStdString(tokens[2]), std::stoi(tokens[4])};
        c.setEngineType(std::stoi(tokens[3]));
        cars.push_back(c);
    } catch (std::exception& e) {
        auto Num = std::to_string(lineNum);
        throw CustomException(("Error while reading csv file: " + std::string(e.what()) + " line: " + Num));
    }
    }

    fin.close();
    return cars;
}

bool CSVReader::is_open() {
    return fin.is_open();
}
