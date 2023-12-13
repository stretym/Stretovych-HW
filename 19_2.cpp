#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> enterVector(int dimension) {
    std::vector<double> vector;
    vector.reserve(dimension);

    std::cout << "Enter " << dimension << "-dimensional vector:\n";
    for (int i = 0; i < dimension; ++i) {
        double value;
        std::cout << "Enter value for component " << (i + 1) << ": ";
        std::cin >> value;
        vector.push_back(value);
    }

    return vector;
}

double calculateVectorNorm(const std::vector<double>& vector) {
    double norm = 0.0;
    for (double component : vector) {
        norm += component * component;
    }
    return sqrt(norm);
}

int main() {
    int n, dimension;
    std::cout << "Enter the number of vectors (n): ";
    std::cin >> n;

    std::cout << "Enter the dimension of vectors (d): ";
    std::cin >> dimension;

    double sumOfNorms = 0.0;

    for (int i = 0; i < n; i++) {
        std::vector<double> vector = enterVector(dimension);
        double norm = calculateVectorNorm(vector);
        sumOfNorms += norm;
    }

    std::cout << "Sum of norms of the vectors: " << sumOfNorms << std::endl;

    return 0;
}