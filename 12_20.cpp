#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
    double m;
};

double lever_arm_force(const Point& point) {
    return point.m * (point.x + point.y);
}

void find_max_lever_arm_force(const std::vector<Point>& points, Point& max_point1, Point& max_point2) {
    double max_force1 = -INFINITY, max_force2 = -INFINITY;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double force1 = lever_arm_force(points[i]);
            double force2 = lever_arm_force(points[j]);

            if (force1 > max_force1) {
                max_force1 = force1;
                max_point1 = points[i];
            }

            if (force2 > max_force2) {
                max_force2 = force2;
                max_point2 = points[j];
            }
        }
    }
}

int main() {
    const char* filename = "coordinates.txt";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Помилка при відкритті файлу " << filename << "." << std::endl;
        return 1;
    }

    int num_points;
    file >> num_points;

    if (num_points < 2) {
        std::cout << "Недостатньо точок для обчислення важелів сили." << std::endl;
        file.close();
        return 1;
    }

    std::vector<Point> points(num_points);
    for (int i = 0; i < num_points; ++i) {
        file >> points[i].x >> points[i].y >> points[i].m;
    }

    file.close();

    Point max_point1, max_point2;
    find_max_lever_arm_force(points, max_point1, max_point2);

    std::cout << "Точка 1: [" << max_point1.x << ", " << max_point1.y << ", " << max_point1.m << "]" << std::endl;
    std::cout << "Точка 2: [" << max_point2.x << ", " << max_point2.y << ", " << max_point2.m << "]" << std::endl;

    return 0;
}
