#include <iostream>
#include <vector>

class BooleanVector {
private:
    std::vector<bool> data;

public:
    BooleanVector() = default;
    explicit BooleanVector(const std::vector<bool>& input) : data(input) {}

    BooleanVector operator&(const BooleanVector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size for bitwise conjunction.");
        }

        BooleanVector result;
        result.data.reserve(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            result.data.push_back(data[i] && other.data[i]);
        }

        return result;
    }

    BooleanVector operator|(const BooleanVector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size for bitwise disjunction.");
        }

        BooleanVector result;
        result.data.reserve(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            result.data.push_back(data[i] || other.data[i]);
        }

        return result;
    }

    BooleanVector operator~() const {
        BooleanVector result;
        result.data.reserve(data.size());

        for (bool value : data) {
            result.data.push_back(!value);
        }

        return result;
    }

    size_t countOnes() const {
        return std::count(data.begin(), data.end(), true);
    }

    size_t countZeros() const {
        return std::count(data.begin(), data.end(), false);
    }

    void display() const {
        for (bool value : data) {
            std::cout << (value ? '1' : '0') << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::vector<bool> data1 = { true, false, true, true };
    std::vector<bool> data2 = { false, false, true, true };
    BooleanVector vector1(data1);
    BooleanVector vector2(data2);

    BooleanVector conjunctionResult = vector1 & vector2;
    BooleanVector disjunctionResult = vector1 | vector2;
    BooleanVector negationResult = ~vector1;

    std::cout << "Vector 1: ";
    vector1.display();
    std::cout << "Vector 2: ";
    vector2.display();
    std::cout << "Conjunction Result: ";
    conjunctionResult.display();
    std::cout << "Disjunction Result: ";
    disjunctionResult.display();
    std::cout << "Negation Result: ";
    negationResult.display();
    std::cout << "Number of Ones in Vector 1: " << vector1.countOnes() << "\n";
    std::cout << "Number of Zeros in Vector 1: " << vector1.countZeros() << "\n";

    return 0;
}