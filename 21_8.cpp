#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

void generateSentenceAnagrams(const std::vector<std::string>& words) {
    do {
        for (const auto& word : words) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(words.begin(), words.end()));
}

int main(int argc, char* argv[]) {
    std::vector<std::string> inputWords;
    for (int i = 1; i < argc; i++) {
        inputWords.push_back(argv[i]);
    }

    std::cout << "Anagrams:" << std::endl;
    generateSentenceAnagrams(inputWords);
    return 0;
}