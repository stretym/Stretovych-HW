#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file.\n";
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the output file.\n";
        inputFile.close();
        return 1;
    }

    std::string inputWord;
    while (inputFile >> inputWord) {
        for (size_t sepStart = 0; sepStart < inputWord.size();) {
            size_t sepSize =
                std::min(std::min(inputWord.size(),inputWord.find(',', sepStart)),
                    std::min(inputWord.find('!', sepStart),inputWord.find('.', sepStart))) - sepStart;

            for (size_t i = 0; i < sepSize / 2; i++) {
                std::swap(inputWord[sepStart + i], inputWord[sepStart + sepSize - 1 - i]);
            }
            sepSize += 1;
            outputFile << inputWord.substr(sepStart, sepSize);
            sepStart += sepSize;
        }
        outputFile << " ";
    }
    inputFile.close();
    outputFile.close();

    return 0;
}