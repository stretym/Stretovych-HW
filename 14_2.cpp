#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() {
    std::ifstream inputFile("test.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file.\n";
        return 1;
    }
    std::ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        std::cerr << "Error: Unable to open the temporary file.\n";
        inputFile.close();
        return 1;
    }

    bool capitalizeNextWord = false;
    std::string word;

    while (inputFile >> word) {
        if (capitalizeNextWord && !word.empty()) {
            word[0] = static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(word[0])));
        }
        capitalizeNextWord = (word == "die" || word == "der" || word == "das");
        tempFile << word << ' ';
    }
    inputFile.close();
    tempFile.close();
    std::remove("test.txt");
    std::rename("temp.txt", "test.txt");

    return 0;
}