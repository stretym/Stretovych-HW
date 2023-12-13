#include <iostream>
#include <string>

//To make the findMax function work for the RationalFraction type, 
//we need to define the comparison operators
//its primite example because i dont have RationalFraction class structure
class RationalFraction {
private:
    int numerator;
    int denominator;

public:
    RationalFraction(int num, int denom) : numerator(num), denominator(denom) {}

    bool operator>(const RationalFraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool operator<(const RationalFraction& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator>=(const RationalFraction& other) const {
        return !(*this < other);
    }

    bool operator<=(const RationalFraction& other) const {
        return !(*this > other);
    }

    bool operator==(const RationalFraction& other) const {
        return (numerator * other.denominator) == (other.numerator * denominator);
    }

    bool operator!=(const RationalFraction& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const RationalFraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

template <typename T>
T findMax(const T& a, const T& b) {
    return a > b ? a : b;
}


template <>
std::string findMax(const std::string& a, const std::string& b) {
    return a.length() > b.length() ? a : b;
}


int main() {
    int intResult = findMax(5, 10);
    double doubleResult = findMax(3.14, 2.718);

    std::cout << "Max of integers: " << intResult << std::endl;
    std::cout << "Max of doubles: " << doubleResult << std::endl;

    std::string strResult = findMax<std::string>("apple", "banana");
    std::cout << "Max of strings: " << strResult << std::endl;

    RationalFraction fraction1(1, 2);
    RationalFraction fraction2(2, 3);
    RationalFraction maxFraction = findMax<RationalFraction>(fraction1, fraction2);
    std::cout << "Max of RationalFractions: " << maxFraction << std::endl;

    return 0;
}