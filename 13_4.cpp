#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<double> extractDoublesWithSeparator(const std::string& input_string, const std::string& separator, int n) {
    std::vector<double> result;

    std::string remaining_string = input_string;

    if (remaining_string.substr(0, separator.size()) == separator) {
        remaining_string = remaining_string.substr(separator.size());
    }

    while (!remaining_string.empty() && result.size()<n) {
        size_t separator_pos = remaining_string.find(separator);
        const char* ptr = remaining_string.data();
        char* end;
        double number = std::strtod(ptr, &end);

        if (ptr == end) {
            if (separator_pos == std::string::npos) {
                break;
            }
            remaining_string = remaining_string.substr(separator_pos + separator.size());
        }
        else {
            result.push_back(number);
            if (separator_pos == std::string::npos) {
                break;
            }
            remaining_string = remaining_string.substr(separator_pos + separator.size());
        }
    }

    return result;
}

int main() {
    int n;
    std::string input_string;
    std::getline(std::cin, input_string);
    std::cin >> n;
    std::vector<double> extracted_doubles = extractDoublesWithSeparator(input_string, ", ", n);

    for (double num : extracted_doubles) {
        std::cout << num << " ";
    }

    std::cout << '\n';

    return 0;
}