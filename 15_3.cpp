#include <iostream>
#include <vector>

class Polynomial {
public:
    Polynomial() noexcept = default;
    Polynomial(const Polynomial&) noexcept = default;
    Polynomial(Polynomial&&) noexcept = default;
    Polynomial& operator=(const Polynomial&) noexcept = default;
    Polynomial& operator=(Polynomial&&) noexcept = default;
    ~Polynomial() noexcept = default;

    template<size_t N>
    Polynomial(const double(&coefficients)[N]) noexcept : coefficients(coefficients, coefficients + N) {}

    Polynomial(const std::vector<double>& coeffs) noexcept : coefficients(coeffs) {}

    size_t coefficientCount() const noexcept {
        return coefficients.size();
    }

    const double& operator[](size_t at) const noexcept {
        return coefficients[at];
    }

    double& operator[](size_t at) noexcept {
        return coefficients[at];
    }

    void addCoefficient(double coeff) noexcept {
        coefficients.push_back(coeff);
    }

protected:
    std::vector<double> coefficients;
};

std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    size_t degree = poly.coefficientCount();
    while (degree--) {
        out << poly[degree] << " * x^" << degree;
        if (degree != 0) {
            out << " + ";
        }
    }
    return out;
}

int main() {
    std::cout << "Enter the number of coefficients: ";
    size_t n;
    std::cin >> n;

    std::vector<double> coefficients;
    double coeff;

    for (size_t i = 0; i < n; ++i) {
        std::cout << "Enter coefficient " << i + 1 << ": ";
        std::cin >> coeff;
        coefficients.push_back(coeff);
    }
    const Polynomial polynomial(coefficients);

    std::cout << "Polynomial representation: " << polynomial << '\n';
    std::cout << "Coefficients count: " << polynomial.coefficientCount() << '\n';

    return 0;
}