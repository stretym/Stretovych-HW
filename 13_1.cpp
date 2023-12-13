#include <iostream>
#include <string>

std::string getSubstring(const std::string& s) {
    size_t colon = s.find(':');
    if (colon == std::string::npos) 
        return s;

    size_t r = colon + 1;
    return s.substr(r, s.find(',', r) - r);
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << getSubstring(s) << '\n';
    return 0;
}