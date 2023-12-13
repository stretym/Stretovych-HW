#include <iostream>
#include <algorithm>
#include <string>

void generateAnagrams(const std::string& word) {
    std::string wordCopy = word;
    do {
        std::cout << wordCopy << std::endl;
    } while (std::next_permutation(wordCopy.begin(), wordCopy.end()));
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <word>" << std::endl;
        return 1;
    }
    std::string inputWord = argv[1];

    std::cout << "Anagrams of \"" << inputWord << "\":" << std::endl;
    generateAnagrams(inputWord);

    return 0;
}