#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> m(n);
    std::vector<double> x(n);

    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    constexpr const char* input_file = "F.txt";
    constexpr const char* output_file = "G.txt";
    std::ifstream f(input_file);
    if (!f.is_open() || f.bad()) {
        std::cout << "Error opening file\n";
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        f >> x[i];
    }

    std::ofstream ff(output_file);
    if (!ff.is_open() || ff.bad()) {
        std::cout << "Error opening file\n";
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        ff << std::pow(x[i], m[i]) << ' ';
    }
}