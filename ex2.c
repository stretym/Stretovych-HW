#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    double sideA, sideB;
    printf("Enter the lengths of two sides (a b): ");
    scanf("%lf %lf", &sideA, &sideB);

    double hypotenuse = hypot(sideA, sideB);

    printf("The hypotenuse of the right triangle with sides %.2lf and %.2lf is: %.4lf\n", sideA, sideB, hypotenuse);

    return 0;
}

