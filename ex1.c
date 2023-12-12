#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    double inputAngle;
    printf("Enter an angle in radians: ");
    scanf("%lf", &inputAngle);

    double cosineValue = cos(inputAngle);

    printf("The cosine of %.2lf radians is: %.4lf\n", inputAngle, cosineValue);

    return 0;
}

