#include <stdio.h>

// Функція для дзеркального відображення матриці
void mirrorVertical(int matrix[][3]) {
    int temp;

    // Прохід по кожному рядку матриці та обмін елементів
    for (int i = 0; i < 3; ++i) {
        // Обмін лівого та правого елементів
        temp = matrix[i][0];
        matrix[i][0] = matrix[i][2];
        matrix[i][2] = temp;
    }
}

// Функція для виведення матриці 
void printMatrix(int matrix[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Ініціалізація квадратної матриці порядку 2 + 1 (розмірністю 3x3)
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // Дзеркальне відображення матриці
    mirrorVertical(matrix);

    // Виведення початкової матриці та результату
    printf("Початкова матриця:\n");
    printMatrix(matrix);

    return 0;
}
