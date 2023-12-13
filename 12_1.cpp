#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x, y;
    std::cin >> x;
    std::cin >> y;
    double response = std::pow(x, y);
    std::cout << "x ^ y = " << response << '\n' << "x ^ y = " << std::scientific << response << '\n';

}