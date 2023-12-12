#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double calculateTriangleArea(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
    double ab_x = b_x - a_x;
    double ab_y = b_y - a_y;
    double ac_x = c_x - a_x;
    double ac_y = c_y - a_y;

    double area = fabs(ab_x * ac_y - ac_x * ab_y) * 0.5;

    return area;
}

double calculateVectorLength(double x, double y) {
    return hypot(x, y);
}

double calculateTriangleAreaHerone(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
    double ab_x = b_x - a_x;
    double ab_y = b_y - a_y;
    double ac_x = c_x - a_x;
    double ac_y = c_y - a_y;
    double bc_x = c_x - b_x;
    double bc_y = c_y - b_y;

    double ab_len = calculateVectorLength(ab_x, ab_y);
    double ac_len = calculateVectorLength(ac_x, ac_y);
    double bc_len = calculateVectorLength(bc_x, bc_y);

    double p = (ab_len + ac_len + bc_len) * 0.5;

    double area = sqrt(p * (p - ab_len) * (p - ac_len) * (p - bc_len));

    return area;
}

int main(void) {
    double x1, x2, x3;
    double y1, y2, y3;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);

    printf("area: %lf\n", calculateTriangleArea(x1, y1, x2, y2, x3, y3));
    printf("area_herone: %lf\n", calculateTriangleAreaHerone(x1, y1, x2, y2, x3, y3));

    return 0;
}
