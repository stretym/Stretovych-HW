#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    constexpr size_t MAX_NUM_WIDTH = 8;

    int n;
    std::cin >> n;
    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);
    std::cout << '\n';
    std::cout.fill(' ');
    for (int i = 1; i <= n; i++) {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << i;
    }
    std::cout << '\n';
    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);
    std::cout << '\n';
    std::cout.fill(' ');
    std::cout << std::setprecision(3);
    for (int i = 1; i <= n; i++) {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << std::sqrt(i);
    }
    std::cout << '\n';
    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);
    std::cout << '\n';
}