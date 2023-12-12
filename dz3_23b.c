#include <stdio.h>

// Функція ReLu(x)
double ReLu(double x) {
    return (x > 0) ? x : 0;
}

// Функція для обчислення похідної ReLu(x)
double ReLuDerivative(double x) {
    return (x > 0) ? 1 : 0;
}

int main() {
    // Приклад використання функцій
    double inputValue = 2.5;
    double outputValue = ReLu(inputValue);
    double derivativeValue = ReLuDerivative(inputValue);

    // Виведення результатів
    printf("ReLu(%f) = %f\n", inputValue, outputValue);
    printf("Derivative of ReLu(%f) = %f\n", inputValue, derivativeValue);

    return 0;
}
