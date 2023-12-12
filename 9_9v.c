#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функція для виділення пам'яті під динамічний двовимірний масив
double** createMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Функція для заповнення матриці випадковими числами
void fillRandomMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (double)rand() / RAND_MAX; // Випадкове число в діапазоні [0, 1)
        }
    }
}

// Функція для виведення матриці 
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функція для додавання рядка в кінець матриці
double** addRowToEnd(double** matrix, int* rows, int cols) {
    // Збільшення кількості рядків на 1
    (*rows)++;

    // Реалокація пам'яті для нового рядка
    matrix = (double**)realloc(matrix, (*rows) * sizeof(double*));
    matrix[(*rows) - 1] = (double*)malloc(cols * sizeof(double));

    
    printf("Введіть значення нового рядка:\n");
    for (int j = 0; j < cols; ++j) {
        scanf("%lf", &matrix[(*rows) - 1][j]);
    }

    return matrix;
}

// Функція для виведення матриці на екран
int main() {
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    int rows, cols;

    // Введення розмірів матриці
    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    // Створення та заповнення матриці випадковими числами
    double** matrix = createMatrix(rows, cols);
    fillRandomMatrix(matrix, rows, cols);

    // Виведення початкової матриці
    printf("Початкова матриця:\n");
    printMatrix(matrix, rows, cols);

    // Додавання нового рядка в кінець матриці
    matrix = addRowToEnd(matrix, &rows, cols);

    // Виведення зміненої матриці
    printf("Матриця після додавання нового рядка:\n");
    printMatrix(matrix, rows, cols);

    // Звільнення виділеної пам'яті
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
