#include <iostream>
#include <fstream>
#include <vector>

int main() {
    const char* inputFileName = "F.txt";
    const char* outputOddFileName = "N.txt";
    const char* outputEvenFileName = "G.txt";

    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл " << inputFileName << std::endl;
        return 1;
    }

    std::ofstream outputOddFile(outputOddFileName);
    std::ofstream outputEvenFile(outputEvenFileName);

    if (!outputOddFile.is_open() || !outputEvenFile.is_open()) {
        std::cerr << "Не вдалося відкрити один з вихідних файлів." << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    // Зчитуємо рядки з файлу F
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Розділяємо рядки за парною/непарною довжиною
    for (const auto& str : lines) {
        if (str.length() % 2 == 0) {
            // Рядок парної довжини - записуємо в файл G
            outputEvenFile << str << std::endl;
        } else {
            // Рядок непарної довжини - записуємо в файл N
            outputOddFile << str << std::endl;
        }
    }

    // Закриваємо файли
    inputFile.close();
    outputOddFile.close();
    outputEvenFile.close();

    std::cout << "Розподіл рядків за парною/непарною довжиною завершено." << std::endl;

    return 0;
}
