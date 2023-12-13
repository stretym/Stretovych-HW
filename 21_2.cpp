#include <iostream>
#include <vector>

void rearrangeList(std::vector<int>& nums, int x) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        while (nums[left] <= x && left < right) {
            left++;
        }
        while (nums[right] > x && left < right) {
            right--;
        }
        if (left < right) {
            std::swap(nums[left], nums[right]);
        }
    }
}

int main() {
    //terminate with non-integer
    std::cout << "Enter the list of integers: ";
    std::vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int x;
    std::cout << "Enter the number X: ";
    std::cin >> x;
    rearrangeList(nums, x);
    std::cout << "Rearranged List: ";
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}