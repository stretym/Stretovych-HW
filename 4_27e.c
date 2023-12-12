#include <stdio.h>
#include <math.h>

// Функція для обчислення числа π
double calculatePi(double tolerance) {
    double pi = 0.0;
    double term = 1.0;
    int k = 0;

    while (fabs(term) >= tolerance) {
        pi += term;
        k++;

        // Оновлення значення term
        term = pow(-1, k) / pow(16, k) * (
            8.0 / (8 * k + 2) +
            4.0 / (8 * k + 3) +
            4.0 / (8 * k + 4) -
            2.0 / (8 * k + 7)
        );
    }

    return pi;
}

int main() {
    double tolerance;

      
    printf("Введіть точність: ");
    scanf("%lf", &tolerance);

  
    double pi = calculatePi(tolerance);
    printf("Обчислене значення π: %.15lf\n", pi);

    return 0;
}
