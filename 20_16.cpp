#include <iostream>
#include <vector>
#include <map>

std::map<int, std::vector<int>> groupByLastDigit(const std::vector<int>& V) {
    std::map<int, std::vector<int>> M;

    for (int element : V) {
        // Отримати останню цифру елементу
        int lastDigit = std::abs(element % 10);

        // Додати елемент до відповідної групи
        M[lastDigit].push_back(element);
    }

    return M;
}

int main() {
    // Ввести вектор цілих чисел
    std::vector<int> V = {123, 45, 678, 90, 321, 456, 789, 12, 34, 567};

    // Виконати групування за останньою цифрою
    std::map<int, std::vector<int>> groupedMap = groupByLastDigit(V);

    // Вивести результат групування
    for (const auto& entry : groupedMap) {
        std::cout << entry.first << ": ";
        for (int value : entry.second) {
            std::cout << value << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
