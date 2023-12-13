#include <iostream>
#include <cmath>

class Point {
public:
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}

    double x{}, y{};

    static Point read_point() {
        Point p;
        std::cout << "Enter x and y coordinates separated by space: ";
        std::cin >> p.x >> p.y;
        readed_count += 1;
        return p;
    }

    static void show_count() {
        std::cout << "Total points read: " << readed_count << '\n';
    }

protected:
    static uint32_t readed_count;
};

uint32_t Point::readed_count;

double distance(const Point& a, const Point& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

int main() {
    double perimeter = 0;
    Point previousPoint = Point::read_point();
    Point firstPoint = previousPoint;

    while (true) {
        std::cout << "Do you want to enter another point? (y/n): ";
        char answer;
        std::cin >> answer;

        if (answer != 'y' && answer != 'Y')
            break;

        Point currentPoint = Point::read_point();
        perimeter += distance(previousPoint, currentPoint);
        previousPoint = currentPoint;
    }

    perimeter += distance(previousPoint, firstPoint);

    std::cout << "Perimeter: " << perimeter << '\n';
    Point::show_count();

    return 0;
}