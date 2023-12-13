#include <iostream>
#include <cmath>

double epsilon = 1e-10;

bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)
{
    if (x2 <= std::max(x1, x3) && x2 >= std::min(x1, x3) &&
        y2 <= std::max(y1, y3) && y2 >= std::min(y1, y3))
        return true;
    return false;
}
int orientation(double x1, double y1, double x2, double y2, double x3, double y3)
{
    int val = (y2 - y1) * (x3 - x2) -
        (x2 - x1) * (y3 - y2);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

class Point {
protected:
    double x{}, y{};
    int dimension;

public:
    Point(int dim) : dimension(dim) {}

    Point(int x_i, int y_i, int dim) : x(x_i), y(y_i), dimension(dim) {}

    virtual void input() {
        std::cout << "Enter coordinates for " << dimension << "D point: ";
        if (dimension >= 1) std::cin >> x;
        if (dimension >= 2) std::cin >> y;
    }

    virtual void output() const {
        std::cout << dimension << "D Point: (" << x;
        if (dimension >= 2) std::cout << ", " << y;
        if(dimension<3) std::cout << ")\n";
    }

    int getDimension() const {
        return dimension;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

class Point3D : public Point {
private:
    double z;

public:
    Point3D() : Point(3), z(0) {}

    Point3D(int x, int y, int z_i) : Point(x,y,3), z(z_i){}

    void input() override {
        Point::input();
        if (dimension >= 3) std::cin >> z;
    }

    void output() const override {
        Point::output();
        if (dimension >= 3) std::cout << ", " << z;
        std::cout << ")\n";
    }

    Point3D operator-(const Point3D& other) const {
        return Point3D(x - other.x, y - other.y, z - other.z);
    }

    Point3D operator*(const double multip) const {
        return Point3D(x* multip, y * multip, z * multip);
    }

    double getZ() const {
        return z;
    }
};

template<typename PointType>
class Line {
private:
    PointType  start, end;

public:
    Line(PointType start, PointType end) : start(start), end(end) {}

    double length() const {
        if (start.getDimension() != end.getDimension()) {
            std::cerr << "Error: Points have different dimensions.\n";
            return 0.0;
        }

        double len = 0.0;
        if (start.getDimension() >= 1) len += std::pow(end.getX() - start.getX(), 2);
        if (start.getDimension() >= 2) len += std::pow(end.getY() - start.getY(), 2);
        if (start.getDimension() >= 3) len += std::pow(end.getZ() - start.getZ(), 2);

        return std::sqrt(len);
    }

    bool intersects(const Line& other) const {
        if (start.getDimension() != other.start.getDimension()) {
            std::cerr << "Error: Lines have different dimensions.\n";
            return false;
        }

        if (start.getDimension() == 2) {
            double x1 = start.getX(), y1 = start.getY();
            double x2 = end.getX(), y2 = end.getY();
            double x3 = other.start.getX(), y3 = other.start.getY();
            double x4 = other.end.getX(), y4 = other.end.getY();
            int o1 = orientation(x1,y1,x2,y2,x3,y3);
            int o2 = orientation(x1, y1, x2, y2, x4, y4);
            int o3 = orientation(x3, y3, x4, y4, x1, y1);
            int o4 = orientation(x3, y3, x4, y4, x2, y2);

            if (o1 != o2 && o3 != o4)
                return true;

            if (o1 == 0 && onSegment(x1, y1, x3, y3, x2, y2)) return true;
            if (o2 == 0 && onSegment(x1, y1, x4, y4, x2, y2)) return true;
            if (o3 == 0 && onSegment(x3, y3, x1, y1, x4, y4)) return true;
            if (o4 == 0 && onSegment(x3, y3, x2, y2, x4, y4)) return true;

            return false;
        }
        else if (start.getDimension() == 3) {
            Point3D P1 = start, P2 = end;
            Point3D Q1 = other.start, Q2 = other.end;
            double a = dot(P2 - P1, Q1 - P1) / pow(normSquared(P2 - P1), 2);
            double b = dot(P2 - P1, Q2 - Q1) / pow(normSquared(P2 - P1), 2);
            
            Point3D C = (P2 - P1) *b - (Q2 - Q1);
            double t1 = dot(C, Q1 -  P1* (1 - a) - P2 * a) / pow(normSquared(C), 2);
            double t2 = a + t1 * b;
            return (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0);
        }

        return false;
    }
private:
    static double dot(const Point3D& v1, const Point3D& v2) {
        return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
    }

    static double normSquared(const Point3D& v) {
        return v.getX() * v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ();
    }
};

int main() {
    Point point2D_1(2);
    point2D_1.input();

    Point point2D_2(2);
    point2D_2.input();

    Line<Point> line2D(point2D_1, point2D_2);

    Point3D point3D_1;
    point3D_1.input();


    Point3D point3D_2;
    point3D_2.input();

    Line<Point3D> line3D(point3D_1, point3D_2);
    std::cout << "Length of the 2D line: " << line2D.length() << std::endl;
    std::cout << "Length of the 3D line: " << line3D.length() << std::endl;
    Point3D point3D_3;
    point3D_1.input();
    Point3D point3D_4;
    point3D_2.input();
    Line<Point3D> line3D_2(point3D_3, point3D_4);
    std::cout << "Lines intersect: " << (line3D.intersects(line3D_2) ? "true" : "false") << std::endl;

    return 0;
}