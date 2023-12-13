#include <iostream>
#include <string>
#include <cctype>

std::string trimWords(const std::string& input_string) {
    bool is_inside_word = false;
    std::string result;
    char previous_char = '\0';

    for (char current_char : input_string) {
        bool is_word_char = std::isalnum(static_cast<unsigned char>(current_char));

        if (is_word_char && is_inside_word || !is_inside_word) {
            result += previous_char;
        }

        previous_char = current_char;
        is_inside_word = is_word_char;
    }

    return result;
}

int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    std::cout << trimWords(input_line) << '\n';

    return 0;
}