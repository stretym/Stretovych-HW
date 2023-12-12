#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    double sideA, sideB, sideC;
    printf("Enter the lengths of three sides (a b c): ");
    scanf("%lf %lf %lf", &sideA, &sideB, &sideC);

    double semiPerimeter = (sideA + sideB + sideC) / 2.0;
    double area = sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));

    printf("The area of the triangle with sides %.2lf, %.2lf, and %.2lf is: %.4lf\n", sideA, sideB, sideC, area);

    return 0;
}

