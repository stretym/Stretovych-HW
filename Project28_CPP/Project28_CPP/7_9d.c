#include <stdio.h>

int main() {
    int n;

    
    printf("Введіть значення n: ");
    scanf("%d", &n);

    // Перевірка, чи n є парним числом
    if (n % 2 != 0) {
        printf("Введіть парне число n.\n");
        return 1;
    }

    // Введення дійсних чисел a1, a2, ..., an
    double a[n];

    printf("Введіть %d дійсних чисел:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("a%d: ", i + 1);
        scanf("%lf", &a[i]);
    }

    // Знаходження min та max
    double minEven = a[1];
    double maxOdd = a[0];

    for (int i = 2; i < n; i += 2) {
        if (a[i] < minEven) {
            minEven = a[i];
        }
    }

    for (int i = 1; i < n; i += 2) {
        if (a[i] > maxOdd) {
            maxOdd = a[i];
        }
    }

    
    printf("min(a2, a4, ...) + max(a1, a3, ...) = %.2lf\n", minEven + maxOdd);

    return 0;
}
