 //15.18

#include <iostream>
#include <cmath>

class PointInTime {
private:
    double x, y;         // Координати точки
    double velocityX, velocityY; // Швидкість по координатах
    double accelerationX, accelerationY; // Прискорення по координатах

public:
    // Конструктор
    PointInTime(double initialX, double initialY,
                double initialVelocityX, double initialVelocityY,
                double initialAccelerationX, double initialAccelerationY)
        : x(initialX), y(initialY),
          velocityX(initialVelocityX), velocityY(initialVelocityY),
          accelerationX(initialAccelerationX), accelerationY(initialAccelerationY) {}

    // Метод для виведення координат точки в момент часу t
    void printPositionAtTime(double t) const {
        double currentX = x + velocityX * t + 0.5 * accelerationX * t * t;
        double currentY = y + velocityY * t + 0.5 * accelerationY * t * t;

        std::cout << "Координати точки в момент часу " << t << ": (" << currentX << ", " << currentY << ")\n";
    }

    // Метод для перевірки можливості перетину траєкторій точок протягом проміжку часу [t1, t2]
    bool checkIntersection(const PointInTime& otherPoint, double t1, double t2) const {
        // Обчислення позначок для точок у задані моменти часу
        double sign1 = velocityX * t1 + 0.5 * accelerationX * t1 * t1 +
                       velocityY * t1 + 0.5 * accelerationY * t1 * t1;
        double sign2 = otherPoint.velocityX * t1 + 0.5 * otherPoint.accelerationX * t1 * t1 +
                       otherPoint.velocityY * t1 + 0.5 * otherPoint.accelerationY * t1 * t1;

        // Перевірка на рівність позначок
        if (sign1 == sign2) {
            // Перевірка на рівність позначок в кінці проміжку [t1, t2]
            sign1 = velocityX * t2 + 0.5 * accelerationX * t2 * t2 +
                    velocityY * t2 + 0.5 * accelerationY * t2 * t2;
            sign2 = otherPoint.velocityX * t2 + 0.5 * otherPoint.accelerationX * t2 * t2 +
                    otherPoint.velocityY * t2 + 0.5 * otherPoint.accelerationY * t2 * t2;

            return sign1 == sign2;
        }

        return false;
    }

    // Метод для визначення відстані між двома точками в конкретний момент часу
    double calculateDistance(const PointInTime& otherPoint, double t) const {
        double deltaX = x + velocityX * t + 0.5 * accelerationX * t * t - (otherPoint.x + otherPoint.velocityX * t + 0.5 * otherPoint.accelerationX * t * t);
        double deltaY = y + velocityY
