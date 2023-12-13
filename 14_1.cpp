#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("test.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file.\n";
        return 1;
    }

    double result;
    inputFile >> result;

    while (true) {
        char operation;
        inputFile >> operation;

        if (operation == '=') {
            break;
        }
        else {
            double operand;
            inputFile >> operand;
            if (operation == '+') {
                result += operand;
            }
            else if (operation == '-') {
                result -= operand;
            }
            else {
                std::cerr << "Error: Invalid operation '" << operation << "'.\n";
                return 1;
            }
        }
    }
    std::cout << "Final Result: " << result << '\n';
    inputFile.close();

    return 0;
}