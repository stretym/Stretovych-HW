#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>

clock_t clockGenerator() {
    return clock();
}

int main() {
    std::list<clock_t> clockList;
    std::generate_n(std::back_inserter(clockList), 10, clockGenerator);
    clockList.unique();
    std::cout << "Unique clock values:\n";
    for (const auto& value : clockList) {
        std::cout << value << '\n';
    }

    return 0;
}