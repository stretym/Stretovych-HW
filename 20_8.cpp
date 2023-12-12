#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>

std::set<std::string> readWordsFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::set<std::string> words;

    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            // Перетворення на нижній регістр для уникнення різниці у регістрі
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.insert(word);
        }
        file.close();
    } else {
        std::cerr << "Не вдалося відкрити файл: " << filePath << std::endl;
    }

    return words;
}

void findCommonWords(const std::set<std::string>& set1, const std::set<std::string>& set2) {
    std::set<std::string> commonWords;
    std::set<std::string> symmetricDifference;

    // Спільні слова
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                          std::inserter(commonWords, commonWords.begin()));

    // Симетрична різниця (неспільні слова)
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                                  std::inserter(symmetricDifference, symmetricDifference.begin()));

    // Виведення результатів
    std::cout << "Спільні слова:" << std::endl;
    for (const auto& word : commonWords) {
        std::cout << word << " ";
    }

    std::cout << "\nСлова, які не є спільними:" << std::endl;
    for (const auto& word : symmetricDifference) {
        std::cout << word << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::string file1Path = "file1.txt";
    std::string file2Path = "file2.txt";

    // Читання слів з файлів
    std::set<std::string> words1 = readWordsFromFile(file1Path);
    std::set<std::string> words2 = readWordsFromFile(file2Path);

    // Пошук та виведення результатів
    findCommonWords(words1, words2);

    return 0;
}
