#include <QCoreApplication>
#include <iostream>
#include <vector>

template <typename T> T averageVector(std::vector<T> vec) {
    if (vec.empty()) {
        return 0;
    }

    T sum = 0;
    for (const T& elem : vec) {
        sum += elem;
    }

    return sum / vec.size();

}

template <typename T1, typename T2>
class Point {
public:
    Point(T1 x, T2 y) {
        this->x=x;
        this->y=y;
     }
    T1 x;
    T2 y;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<int> vecInt = {1, 2, 3, 4, 5};
    std::vector<float> vecFloat = {1, 2.5, 3.5, 4.5, 5.5};
    std::vector<Point<int, int>> vecPoint = {Point<int, int>(1, 1), Point<int, int>(2, 2), Point<int, int>(3, 3)};

    std::cout << "Average of vecInt: " << averageVector(vecInt) << std::endl;
    std::cout << "Average of vecFloat: " << averageVector(vecFloat) << std::endl;

    std::vector<int> xCoords, yCoords;
    for (const Point<int, int>& point : vecPoint) {
        xCoords.push_back(point.x);
        yCoords.push_back(point.y);
    }

    std::cout << "Average of x coords of vecPoint: " << averageVector(xCoords) << std::endl;
    std::cout << "Average of y coords of vecPoint: " << averageVector(yCoords) << std::endl;

    return a.exec();
}
