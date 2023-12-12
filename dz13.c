#include <stdio.h>
#include <math.h>

int main() {
    double number;

    // Зчитування числа від користувача
    printf("Введіть число: ");
    scanf("%lf", &number);

    // Перевірка, чи введене число не від'ємне
    if (number <= 0) {
        printf("Десятковий логарифм не визначений для від'ємних або нульових чисел.\n");
    } else {
        // Обчислення десяткового логарифму та виведення результату
        double result = log10(number);
        printf("Десятковий логарифм числа %.3lf: %.3lf\n", number, result);
    }

    return 0;
}
