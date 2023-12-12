#include <stdio.h>

int main() {
    int n;

    
    printf("Введіть значення n: ");
    scanf("%d", &n);

    // Перевірка, чи n не менше двох
    if (n < 2) {
        printf("Введіть n, яке більше або рівне 2.\n");
        return 1;
    }

    // Введення цілих чисел  a(n)
    int a[n];

    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("a(%d): ", i + 1);
        scanf("%d", &a[i]);
    }

    // Знаходження min
    int minSum = a[0] + a[1];

    for (int i = 1; i < n - 1; ++i) {
        int currentSum = a[i] + a[i + 1];
        if (currentSum < minSum) {
            minSum = currentSum;
        }
    }

    
    printf("min(a(1) + a(2), ..., a(n-1) + a(n)) = %d\n", minSum);

    return 0;
}
