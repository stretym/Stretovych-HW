#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>


int main() {
    constexpr const char* input_file = "input.txt";
    std::vector<int> numbers;
    std::ifstream f(input_file);

    if (!f.is_open() || f.bad()) {
        std::cout << "Error opening file\n";
        return EXIT_FAILURE;
    }

    int n;
    while (f >> n) {
        numbers.push_back(n);
    }

    std::cout << std::setprecision(4);
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << std::sqrt(numbers[numbers.size() - 1 - i]) << '\n';
    }
}