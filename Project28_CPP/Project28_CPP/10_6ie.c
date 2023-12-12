#include <stdio.h>

// Визначення структури для кола
typedef struct {
    double radius;  // Радіус кола
    double centerX; // Координата X центра кола
    double centerY; // Координата Y центра кола
} Circle;

// Функція для введення даних кола з консолі
void inputCircle(Circle *circle) {
    printf("Введіть радіус кола: ");
    scanf("%lf", &circle->radius);

    printf("Введіть координату X центра кола: ");
    scanf("%lf", &circle->centerX);

    printf("Введіть координату Y центра кола: ");
    scanf("%lf", &circle->centerY);
}

// Функція для виведення даних кола на екран
void printCircle(const Circle *circle) {
    printf("Коло з радіусом %.2lf та центром в точці (%.2lf, %.2lf)\n",
           circle->radius, circle->centerX, circle->centerY);
}

int main() {
    Circle myCircle;

    // Введення даних про коло
    inputCircle(&myCircle);

    // Виведення даних про коло
    printCircle(&myCircle);

    return 0;
}
