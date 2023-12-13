#include <iostream>
#include <vector>

template <typename T>
class Polynomial {
private:
    std::vector<T> coefficients;

public:
    Polynomial() {}
    Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {}

    void input() {
        int degree;
        std::cout << "Enter the degree of the polynomial: ";
        std::cin >> degree;

        coefficients.resize(degree + 1);

        for (int i = degree; i >= 0; --i) {
            std::cout << "Enter the coefficient for x^" << i << ": ";
            std::cin >> coefficients[i];
        }
    }

    void output() const {
        std::cout << "Polynomial: ";
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (i == 0) {
                    std::cout << coefficients[i];
                }
                else {
                    std::cout << coefficients[i] << "x^" << i << " + ";
                }
            }
        }
        std::cout << std::endl;
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> result;
        int size = std::max(coefficients.size(), other.coefficients.size());
        result.coefficients.resize(size, T(0));

        for (int i = 0; i < size; ++i) {
            if (i < coefficients.size()) {
                result.coefficients[i] += coefficients[i];
            }
            if (i < other.coefficients.size()) {
                result.coefficients[i] += other.coefficients[i];
            }
        }

        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        Polynomial<T> result;
        result.coefficients.resize(coefficients.size() + other.coefficients.size() - 1, T(0));

        for (int i = 0; i < coefficients.size(); ++i) {
            for (int j = 0; j < other.coefficients.size(); ++j) {
                result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return result;
    }

    T calculate(T x) const {
        T result = 0;
        T powerX = 1;

        for (const T& coefficient : coefficients) {
            result += coefficient * powerX;
            powerX *= x;
        }

        return result;
    }
};

int main() {
    Polynomial<double> poly1, poly2, result;
    std::cout << "Enter coefficients for the first polynomial:\n";
    poly1.input();
    std::cout << "Enter coefficients for the second polynomial:\n";
    poly2.input();
    std::cout << "\nPolynomial 1:\n";
    poly1.output();
    std::cout << "\nPolynomial 2:\n";
    poly2.output();

    result = poly1 + poly2;
    std::cout << "\nAddition Result:\n";
    result.output();
    result = poly1 * poly2;
    std::cout << "\nMultiplication Result:\n";
    result.output();
    double x;
    std::cout << "\nEnter the value of x to calculate the polynomial:\n";
    std::cin >> x;
    std::cout << "Polynomial value at x = " << x << ": " << poly1.calculate(x) << std::endl;

    return 0;
}