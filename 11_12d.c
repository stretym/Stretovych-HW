#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представлення іграшок
typedef struct {
    char name[50];
    double price;
    int minAge;
    int maxAge;
} Toy;

// Функція для зчитування даних про іграшки з файлу
int readToysFromFile(const char *filename, Toy **toys, int *numToys) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Помилка при відкритті файлу %s.\n", filename);
        return 0;
    }

    // Визначення кількості іграшок у файлі
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    *numToys = (int)(fileSize / sizeof(Toy));
    rewind(file);

    // Виділення пам'яті для зчитування масиву іграшок
    *toys = (Toy *)malloc(*numToys * sizeof(Toy));
    if (*toys == NULL) {
        printf("Помилка виділення пам'яті.\n");
        fclose(file);
        return 0;
    }

    // Зчитування іграшок з файлу
    fread(*toys, sizeof(Toy), *numToys, file);

    fclose(file);
    return 1;
}

// Функція для виведення даних про іграшки на консоль
void printToys(const Toy *toys, int numToys) {
    printf("Список іграшок:\n");
    for (int i = 0; i < numToys; ++i) {
        printf("Іграшка: %s, Ціна: %.2lf грн, Вікові межі: %d-%d років\n",
               toys[i].name, toys[i].price, toys[i].minAge, toys[i].maxAge);
    }
}

// Функція для визначення ціни всіх товарів з певною назвою
double calculateTotalPriceByName(const Toy *toys, int numToys, const char *targetName) {
    double totalPrice = 0.0;

    for (int i = 0; i < numToys; ++i) {
        if (strcmp(toys[i].name, targetName) == 0) {
            totalPrice += toys[i].price;
        }
    }

    return totalPrice;
}

int main() {
    const char *filename = "toys.bin";
    Toy *toys;
    int numToys;

    // Зчитування масиву іграшок з файлу
    if (!readToysFromFile(filename, &toys, &numToys)) {
        return 1;
    }

    // Виведення іграшок на консоль
    printToys(toys, numToys);

    // Визначення ціни всіх товарів з певною назвою та виведення на консоль
    char targetName[50];
    printf("\nВведіть назву іграшки для визначення ціни: ");
    scanf("%s", targetName);
    
    double totalPrice = calculateTotalPriceByName(toys, numToys, targetName);
    printf("Загальна ціна іграшок з назвою %s: %.2lf грн\n", targetName, totalPrice);

    // Звільнення виділеної пам'яті
    free(toys);

    return 0;
}
