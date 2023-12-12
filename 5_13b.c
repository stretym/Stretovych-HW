#include <stdio.h>

// Функція для обчислення добутку P(n)
double calculateProduct(int n, double (*a)(int), double (*b)(int)) {
    double result = 1.0;

    for (int k = 1; k <= n; ++k) {
        result *= a(k) * b(k);
    }

    return result;
}

// Приклад функції a(k)
double functionA(int k) {
    return 2.0 * k;
}

// Приклад функції b(k)
double functionB(int k) {
    return 3.0 / (k + 1);
}

int main() {
    int n;

    // Введення значення n
    printf("Введіть значення n: ");
    scanf("%d", &n);

    // Обчислення та виведення результату
    double result = calculateProduct(n, functionA, functionB);
    printf("P(%d) = %lf\n", n, result);

    return 0;
}
