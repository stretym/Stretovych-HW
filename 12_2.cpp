#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::vector<unsigned long long> numbers;

    for (size_t i = 0; i + 10 <= s.size(); i += 10) {
        unsigned long long num = std::stoull(s.substr(i, 10));
        numbers.push_back(num);
    }
    unsigned long long sum = std::accumulate(numbers.begin(), numbers.end(), 0ULL);

    std::cout << sum << '\n';
}