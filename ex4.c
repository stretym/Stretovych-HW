#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double polynomialA(double x) {
    double x2 = x * x;
    return x2 * x2 + 2 * x2 + 1;
}

double polynomialB(double x) {
    double x2 = x * x;
    x += 1.;
    return (x2 + x) * x2 + x;
}

double polynomialE(double x) {
    x *= 2.;
    double x2 = x * x;
    x += 1.;
    return (x2 + x) * x2 + x;
}

double polynomialEGeometric(double x) {
    x *= 2.;
    double x2 = x * x;
    return (x2 * x2 * x - 1.) / (x - 1.);
}

int main(void) {
    double inputValue;
    scanf("%lf", &inputValue);

    printf("a(x) = %lf\n", polynomialA(inputValue));
    printf("b(x) = %lf\n", polynomialB(inputValue));
    printf("e(x) = %lf\n", polynomialE(inputValue));
    printf("e_geometric(x) = %lf\n", polynomialEGeometric(inputValue));

    return 0;
}

