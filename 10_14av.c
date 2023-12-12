#include <stdio.h>

// Структура для представлення запису про людину
typedef struct {
    int nameNumber;  
    char gender;    
    double height;   
} Person;

// Функція для обчислення середнього зросту жінок
double averageHeightOfWomen(const Person* people, int size) {
    int countWomen = 0;
    double totalHeightWomen = 0.0;

    for (int i = 0; i < size; ++i) {
        if (people[i].gender == 'F') {
            countWomen++;
            totalHeightWomen += people[i].height;
        }
    }

    if (countWomen > 0) {
        return totalHeightWomen / countWomen;
    } else {
        return 0.0;  // Якщо немає жінок, повертаємо 0
    }
}

// Функція для перевірки однакового зросту та виведення імені людини
void checkAndPrintSameHeight(const Person* people, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (people[i].height == people[j].height) {
                printf("Зріст %s та %s однаковий: %.2lf\n", 
                       people[i].nameNumber, people[j].nameNumber, people[i].height);
            }
        }
    }
}

int main() {
    // Приклад використання:
    const int size = 3;
    Person people[size] = {
        {1, 'M', 175.5},
        {2, 'F', 162.0},
        {3, 'F', 170.3}
    };

    // Обчислення та виведення середнього зросту жінок
    double avgHeight = averageHeightOfWomen(people, size);
    printf("Середній зріст жінок: %.2lf\n", avgHeight);

    // Перевірка на однаковий зріст та виведення імені людини
    checkAndPrintSameHeight(people, size);

    return 0;
}
