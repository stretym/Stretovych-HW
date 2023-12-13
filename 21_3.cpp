#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int sumOfLargestK(const std::vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size()) {
        std::cerr << "Invalid value of k." << std::endl;
        return 0;
    }

    std::vector<int> copy = nums;
    std::sort(copy.begin(), copy.end(), std::greater<int>());

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += copy[i];
    }

    return sum;
}


std::vector<int> kSmallestNumbers(const std::vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size()) {
        std::cerr << "Invalid value of k." << std::endl;
        return std::vector<int>();
    }

    std::vector<int> copy = nums;
    std::partial_sort(copy.begin(), copy.begin()+k, copy.end());

    return std::vector<int>(copy.begin(), copy.begin() + k);
}

int main() {
    std::vector<int> numbers = { 5, 2, 8, 1, 3, 9, 4, 7, 6 };
    int k = 3;
    int sum = sumOfLargestK(numbers, k);
    std::cout << "Sum of the largest " << k << " numbers: " << sum << std::endl;
    std::vector<int> smallestNums = kSmallestNumbers(numbers, k);
    std::cout << "Array of the smallest " << k << " numbers: ";
    for (const auto& num : smallestNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}