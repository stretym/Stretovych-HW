#include <stdio.h>

// Функція для обчислення факторіалу числа
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція для обчислення елементів послідовності
double calculateElement(double x, int k) {
    double result = 1.0;

    for (int i = 1; i <= 2 * k; ++i) {
        result *= x;
        result /= i;
    }

    return result;
}

int main() {
    double x;
    int k;

    
    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть значення k: ");
    scanf("%d", &k);

    
    double result = calculateElement(x, k);
    printf("x(%d) = %lf\n", k, result);

    return 0;
}
