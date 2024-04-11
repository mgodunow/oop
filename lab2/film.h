#include <string>
#include <vector>
#include <QString>

#ifndef FILM_H
#define FILM_H

class Film
{

private:
    enum Genre
    {
        DRAMA, THRILLER, ROMANCE, FANTASY, ACTION, HORROR
    };

    int Id;
    QString Name;
    Genre Genre;
    int Year;


public:
    Film(int id, QString name, enum Genre genre, int year);
    ~Film();

    static QString search();
    static std::vector<Film> readFile(QString path);
    static void saveFile(QString path, std::vector<Film> films, bool condition);
    static Film addFilm(int id, QString name, QString genre, int year);
    static enum Genre setGenre(QString str);

    int getId();
    QString getName();
    enum Genre getGenre();
    int getYear();
    QString getGenreString();
};

#endif // FILM_H
