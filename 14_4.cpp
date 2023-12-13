#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file.\n";
        return 1;
    }

    std::string tag;
    std::vector<std::string> tagStack;

    while (inputFile >> tag) {
        if (tag.front() == '<') {
            if (!tag.back() == '>') {
                std::cout << "Error: Incorrect format - missing `>` for tag: " << tag << '\n';
                return 1;
            }

            if (tag[1]) {
                if (tagStack.empty()) {
                    std::cout << "Error: Incorrect format - no open tag for closing tag: " << tag << '\n';
                    return 1;
                }

                if (tagStack.back() != tag.substr(2, tag.size() - 3)) {
                    std::cout << "Error: Incorrect format - tags don't match: " << tag << '\n';
                    return 1;
                }

                tagStack.pop_back();
            }
            else {
                tagStack.push_back(tag.substr(1, tag.size() - 2));
            }
        }
    }

    if (tagStack.empty()) {
        std::cout << "Correct: All tags are properly opened and closed.\n";
    }
    else {
        std::cout << "Error: Incorrect format - unclosed tags present.\n";
        return 1;
    }
    inputFile.close();

    return 0;
}