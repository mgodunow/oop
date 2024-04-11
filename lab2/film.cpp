#include <fstream>
#include <algorithm>
#include <QDebug>
#include <QFileDialog>

#include "film.h"



Film::Film(int id, QString name, enum Genre genre, int year){
    Id = id;
    Name = name;
    Genre = genre;
    Year = year;
}

int Film::getId(){
    return Id;
}

QString Film::getName(){
    return Name;
}

enum Film::Genre Film::getGenre(){
    return Genre;
}

int Film::getYear(){
    return Year;
}

Film::~Film(){

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

QString Film::search(){
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

std::vector<Film> Film::readFile(QString path){
    std::vector<Film> films;
    std::ifstream fin(path.toStdString());
    while(!fin.eof()){
       std::string line;
       std::getline(fin, line);
       if(line == "") continue;
       auto tokens = split_line(line, ';');
       Film f = {std::stoi(tokens[0]), QString::fromStdString(tokens[1]), static_cast<enum Genre>(std::stoi(tokens[2])), std::stoi(tokens[3])};
       films.push_back(f);
   }
   fin.close();
   return films;
}

void Film::saveFile(QString path, std::vector<Film> films, bool condition){
    std::ofstream fout(path.toStdString());
    if(fout.is_open())
        for(auto& f : films)
            if((f.getGenre() == 2 && f.getYear() >= 2010) || !condition)
                fout << f.getId() << ";" << f.getName().toStdString() << ";" << f.getGenre() << ";" << f.getYear() << "\n";

    fout.close();
}

Film addFilm(int id, QString name, QString genre, int year){
    Film f = {id, name, Film::setGenre(genre), year};
    return f;
}

QString Film::getGenreString(){
    int num = Genre;
    QString str;
    switch (num) {
        case 0:
            str = "Drama";
        break;
        case 1:
            str = "Thriller";
        break;
        case 2:
            str = "Romance";
        break;
        case 3:
            str = "Fantasy";
        break;
        case 4:
            str = "Action";
        break;
        case 5:
            str = "Horror";
        break;
    }
    return str;
}

enum Film::Genre Film::setGenre(QString str){
    str = str.toUpper();
    enum Genre genre;
    if(str == "DRAMA"){
        genre = static_cast<enum Genre>(std::stoi("0"));
    } else if(str == "THRILLER"){
        genre = static_cast<enum Genre>(std::stoi("1"));
    } else if(str == "ROMANCE"){
        genre = static_cast<enum Genre>(std::stoi("2"));
    } else if(str == "FANTASY"){
        genre = static_cast<enum Genre>(std::stoi("3"));
    } else if(str == "ACTION"){
        genre = static_cast<enum Genre>(std::stoi("4"));
    } else if(str == "HORROR"){
        genre = static_cast<enum Genre>(std::stoi("5"));
    }

    return genre;
}
