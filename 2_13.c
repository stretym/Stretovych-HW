#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double calculateTorusVolume(double innerRadius, double outerRadius) {
    const double pi = 3.141592653589793;

    double volume = 2.0 * pi * pi * innerRadius * outerRadius * outerRadius;

    return volume;
}

int main(void) {
    double innerRadius, outerRadius;

    printf("Enter the inner radius of the torus: ");
    scanf("%lf", &innerRadius);

    printf("Enter the outer radius of the torus: ");
    scanf("%lf", &outerRadius);

    if (innerRadius < 0 || outerRadius < 0 || innerRadius >= outerRadius) {
        printf("Invalid input. Please ensure that the inner radius is non-negative and less than the outer radius.\n");
        return 1; // Exit with an error code
    }

    double torusVolume = calculateTorusVolume(innerRadius, outerRadius);

    printf("The volume of the torus with inner radius %.2lf and outer radius %.2lf is: %.4lf\n", innerRadius, outerRadius, torusVolume);

    return 0;
}

