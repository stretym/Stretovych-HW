#include <stdio.h>
#include <stdlib.h>

// Функція для зчитування масиву з файлу
int readArrayFromFile(const char *filename, int **array, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка при відкритті файлу %s.\n", filename);
        return 0;
    }

    // Визначення кількості чисел у файлі
    int count = 0;
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        count++;
    }

    // Виділення пам'яті для зчитування масиву
    *array = (int *)malloc(count * sizeof(int));
    if (*array == NULL) {
        printf("Помилка виділення пам'яті.\n");
        fclose(file);
        return 0;
    }

    // Зчитування чисел з файлу
    rewind(file);
    for (int i = 0; i < count; ++i) {
        fscanf(file, "%d", &(*array)[i]);
    }

    fclose(file);
    *size = count;
    return 1;
}

// Функція для запису масиву в файл
void writeArrayToFile(const char *filename, const int *array, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Помилка при відкритті файлу %s для запису.\n", filename);
        return;
    }

    // Запис чисел у файл
    for (int i = 0; i < size; ++i) {
        fprintf(file, "%d ", array[i]);
    }

    fclose(file);
}

// Функція для створення масиву з найбільшими значеннями груп
void createMaxGroupsArray(const int *array, int size, int p, int **maxGroupsArray, int *maxGroupsSize) {
    int numGroups = size / p + (size % p != 0);  // Кількість груп
    *maxGroupsSize = numGroups;

    // Виділення пам'яті для масиву з найбільшими значеннями груп
    *maxGroupsArray = (int *)malloc(numGroups * sizeof(int));

    // Запис найбільшого значення з кожної групи у новий масив
    for (int i = 0; i < numGroups; ++i) {
        int maxInGroup = array[i * p];  // Початкове значення - перше число у групі

        for (int j = 1; j < p && i * p + j < size; ++j) {
            if (array[i * p + j] > maxInGroup) {
                maxInGroup = array[i * p + j];
            }
        }

        (*maxGroupsArray)[i] = maxInGroup;
    }
}

int main() {
    const char *filenameF = "F.txt";
    const char *filenameG = "G.txt";
    int *arrayF;
    int sizeF;

    // Зчитування масиву з файлу F
    if (!readArrayFromFile(filenameF, &arrayF, &sizeF)) {
        return 1;
    }

    int p;
    printf("Введіть значення p: ");
    scanf("%d", &p);

    int *maxGroupsArray;
    int maxGroupsSize;

    // Створення масиву з найбільшими значеннями груп
    createMaxGroupsArray(arrayF, sizeF, p, &maxGroupsArray, &maxGroupsSize);

    // Запис масиву з найбільшими значеннями груп у файл G
    writeArrayToFile(filenameG, maxGroupsArray, maxGroupsSize);

    // Виведення результату
    printf("Масив з найбільшими значеннями груп:\n");
    for (int i = 0; i < maxGroupsSize; ++i) {
        printf("%d ", maxGroupsArray[i]);
    }
    printf("\n");

    // Звільнення виділеної пам'яті
    free(arrayF);
    free(maxGroupsArray);

    return 0;
}
