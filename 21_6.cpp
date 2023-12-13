#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Sum {
public:
    Sum() : sum_(0) {}
    void operator()(const T& value) {
        sum_ += value;
    }
    T getSum() const {
        return sum_;
    }
private:
    T sum_;
};

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    Sum<int> sumInt;
    std::for_each(numbers.begin(), numbers.end(), [&](const int& value) {
        sumInt(value);
        });
    std::cout << "Sum of integers: " << sumInt.getSum() << std::endl;

    std::vector<double> values = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    Sum<double> sumDouble;
    std::for_each(values.begin(), values.end(), [&](const double& value) {
        sumDouble(value);
        });
    std::cout << "Sum of doubles: " << sumDouble.getSum() << std::endl;

    return 0;
}