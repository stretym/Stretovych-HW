#include <stdio.h>
#include <stdlib.h>

// Структура для представлення матриці
typedef struct {
    double **data;  // Дані матриці
    int rows;       // Кількість рядків
    int cols;       // Кількість стовпців
} Matrix;

// Функція для виділення пам'яті під матрицю
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    matrix.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        matrix.data[i] = (double *)malloc(cols * sizeof(double));
    }

    return matrix;
}

// Функція для вводу матриці з консолі
void inputMatrix(Matrix *matrix) {
    printf("Введіть елементи матриці %d x %d:\n", matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf("Елемент [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix->data[i][j]);
        }
    }
}

// Функція для очищення пам'яті, виділеної під матрицю
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

// Функція для підрахунку добутку масиву матриць
Matrix multiplyMatrices(Matrix *matrices, int numMatrices) {
    if (numMatrices <= 0) {
        Matrix emptyMatrix = {NULL, 0, 0};
        return emptyMatrix;
    }

    int commonCols = matrices[0].cols;

    for (int i = 1; i < numMatrices; ++i) {
        if (matrices[i].rows != commonCols) {
            printf("Неможливо підрахувати добуток. Кількість стовпців матриці %d не співпадає з кількістю рядків матриці %d.\n",
                   commonCols, matrices[i].rows);
            Matrix emptyMatrix = {NULL, 0, 0};
            return emptyMatrix;
        }
        commonCols = matrices[i].cols;
    }

    // Створення та заповнення результату
    Matrix resultMatrix = createMatrix(matrices[0].rows, commonCols);
    for (int i = 0; i < resultMatrix.rows; ++i) {
        for (int j = 0; j < resultMatrix.cols; ++j) {
            resultMatrix.data[i][j] = 1.0;  // Ініціалізація результату
            for (int k = 0; k < numMatrices; ++k) {
                resultMatrix.data[i][j] *= matrices[k].data[i][j];
            }
        }
    }

    return resultMatrix;
}

// Функція для виведення матриці 
void printMatrix(const Matrix *matrix) {
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf("%lf\t", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int numMatrices;

    // Введення кількості матриць у масиві
    printf("Введіть кількість матриць: ");
    scanf("%d", &numMatrices);

    // Створення масиву матриць
    Matrix *matrices = (Matrix *)malloc(numMatrices * sizeof(Matrix));

    // Введення та виділення пам'яті для кожної матриці
    for (int i = 0; i < numMatrices; ++i) {
        int rows, cols;

        // Введення розмірів матриці
        printf("Матриця %d:\n", i + 1);
        printf("Введіть кількість рядків: ");
        scanf("%d", &rows);
        printf("Введіть кількість стовпців: ");
        scanf("%d", &cols);

        // Виділення пам'яті та введення матриці
        matrices[i] = createMatrix(rows, cols);
        inputMatrix(&matrices[i]);
    }

    // Підрахунок та виведення добутку масиву матриць
    Matrix resultMatrix = multiplyMatrices(matrices, numMatrices);
    if (resultMatrix.data != NULL) {
        printf("Добуток масиву матриць:\n");
        printMatrix(&resultMatrix);
        freeMatrix(&resultMatrix);
    }

    // Очищення пам'яті, виділеної під матриці
    for (int i = 0; i < numMatrices; ++i) {
        freeMatrix(&matrices[i]);
    }
    free(matrices);

    return 0;
}
