#include <stdio.h>


int checkConditionJ(int x, int y, int z) {
    // Перевірка, чи тільки одне з чисел менше за 1001
    if ((x < 1001 && y >= 1001 && z >= 1001) ||
        (y < 1001 && x >= 1001 && z >= 1001) ||
        (z < 1001 && x >= 1001 && y >= 1001)) {
        return 1; // Умова виконана
    } else {
        return 0; // Умова не виконана
    }
}

int main() {
    
    if (checkConditionJ(900, 1200, 800)) {
        printf("Умова виконана для чисел 900, 1200, і 800\n");
    } else {
        printf("Умова не виконана для чисел 900, 1200, і 800\n");
    }

    return 0;
}
