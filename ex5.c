#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double rosenbrock(double x, double y) {
    double t1 = x * x - y;
    double t2 = x - 1.;
    return 100. * t1 * t1 + t2 * t2;
}

int main(void) {
    printf("%lf\n", rosenbrock(0., 1.));
    printf("%lf\n", rosenbrock(1., 1.));
    printf("%lf\n", rosenbrock(1., 0.));

    return 0;
}

