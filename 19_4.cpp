#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cout << "Enter the number of rows (n): ";
    std::cin >> n;

    std::cout << "Enter the number of columns (m): ";
    std::cin >> m;

    if (n <= 0 || m <= 0 || n >= 100 || m >= 100) {
        std::cerr << "Invalid input. n and m should be positive integers less than 100." << std::endl;
        return 1;
    }
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));

    std::cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::vector<std::pair<int, int>> maxElements;

    for (int i = 0; i < n; i++) {
        auto maxIt = std::max_element(matrix[i].begin(), matrix[i].end());
        maxElements.emplace_back(*maxIt, i);
    }
    std::sort(maxElements.begin(), maxElements.end(), std::greater<>());
    std::vector<std::vector<int>> swappedMatrix(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        swappedMatrix[i] = matrix[maxElements[i].second];
    }

    // Output the result
    std::cout << "\nMatrix after swapping:\n";
    for (const auto& row : swappedMatrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }

    return 0;
}