#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string surname;
    int group;
    std::string course;
    std::vector<int> marks;
};

void createExampleFile() {
    std::ofstream outputFile("input.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the output file.\n";
        return;
    }

    std::vector<Student> students = {
        {"johnson", 2, "comp math 1", {25, 28, 18, 30}},
        {"smith", 1, "programming", {15, 22, 27, 18}},
        {"williams", 3, "data structures", {28, 30, 25, 29}}
    };

    for (const auto& student : students) {
        outputFile << student.surname << ", " << student.group << ", "
            << student.course;

        for (int mark : student.marks) {
            outputFile << ", " << mark;
        }

        outputFile << '\n';
    }

    std::cout << "Example file created successfully.\n";
}

int main() {
    createExampleFile();

    std::ifstream dataInput("input.txt");
    std::string lineBuffer;
    std::string bestStudent;
    double lowestAverage = 30.0;

    while (std::getline(dataInput, lineBuffer)) {
        Student student;
        size_t surnameEnd = lineBuffer.find(',');
        size_t groupEnd = lineBuffer.find(',', surnameEnd + 1);
        size_t courseEnd = lineBuffer.find(',', groupEnd + 1);
        student.surname = lineBuffer.substr(0, surnameEnd - 1);
        student.group = std::stoi(lineBuffer.substr(surnameEnd + 2, groupEnd - surnameEnd - 2));
        student.course = lineBuffer.substr(groupEnd + 2, courseEnd - groupEnd - 2);

        size_t markStart = courseEnd + 2;
        while (markStart < lineBuffer.size()) {
            size_t markEnd = lineBuffer.find(',', markStart);
            if (markEnd == std::string::npos) {
                markEnd = lineBuffer.size();
            }

            student.marks.push_back(std::stoi(lineBuffer.substr(markStart, markEnd - markStart)));
            markStart = markEnd + 1;
        }
        double averageMark = 0.0;
        for (int mark : student.marks) {
            averageMark += mark;
        }
        averageMark /= student.marks.size();
        if (averageMark < lowestAverage) {
            bestStudent = student.surname;
            lowestAverage = averageMark;
        }
    }

    if (!bestStudent.empty()) {
        std::cout << "Best student: " << bestStudent << " with average: " << lowestAverage << '\n';
    }
    else {
        std::cout << "No data found.\n";
    }

    return 0;
}