#include <iostream>
#include <algorithm>
#include <cctype>

int main() {
    std::string str = "HdfEFDvdvsdvefsEVdfs23d";
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::toupper(c); });
    std::cout  << str << std::endl;

    return 0;
}