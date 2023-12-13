#include <iostream>
#include <string>
#include <cctype>

void processDots(std::string& input_string) {
    const size_t firstDot = input_string.find('.');
    const size_t lastDot = input_string.rfind('.');

    if (firstDot == std::string::npos) {
        size_t i = 0;
        while (i < input_string.size() && std::isspace(static_cast<unsigned char>(input_string[i]))) {
            ++i;
        }
        input_string.erase(0, i);
    }
    else if (firstDot == lastDot) {
        input_string.erase(0, firstDot+1);
    }
    else {
        input_string.erase(firstDot, lastDot-firstDot+1);
    }
}

int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    processDots(input_line);

    std::cout << input_line << std::endl;

    return 0;
}