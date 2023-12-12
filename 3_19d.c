#include <stdio.h>


int checkConditionD(int number) {
    // Розділення числа на першу і другу цифри
    int firstDigit = number / 10;
    int secondDigit = number % 10;

    // Знаходження суми перших двох цифр
    int sum = firstDigit + secondDigit;

    // Перевірка, чи є сума двозначною
    if (sum >= 10 && sum <= 99) {
        return 1; // Умова виконана
    } else {
        return 0; // Умова не виконана
    }
}

int main() {
   
    if (checkConditionD(37)) {
        printf("Умова d виконана для числа 37\n");
    } else {
        printf("Умова d не виконана для числа 37\n");
    }

    return 0;
}
