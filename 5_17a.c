#include <stdio.h>
#include <math.h>

// Функція для обчислення факторіалу числа
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція для обчислення суми
double calculateSum(double x, double epsilon) {
    double sum = 0.0;
    double term = 1.0;
    int k = 0;

    while (fabs(term) >= epsilon) {
        sum += term;
        k++;

        // Оновлення значення term
        term = pow(x, 2 * k) / (pow(2, k) * factorial(k));
    }

    return sum;
}

int main() {
    double x, epsilon;

    
    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть точність epsilon: ");
    scanf("%lf", &epsilon);

   
    double result = calculateSum(x, epsilon);
    printf("Обчислена сума: %lf\n", result);

    return 0;
}
