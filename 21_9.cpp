#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

struct Point {
    int x, y, z;
};

double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2) + std::pow(p2.z - p1.z, 2));
}

std::vector<Point> readPointsFromFile(const std::string& filename) {
    //1, 2, 3; 3, 4, 5
    std::ifstream inputFile(filename);
    std::vector<Point> points;

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Point point;
            char delimiter;
            if (iss >> point.x >> delimiter >> point.y >> delimiter >> point.z) {
                points.push_back(point);
            }
        }

        inputFile.close();
    }
    else {
        std::cerr << "Unable to open the input file." << std::endl;
    }

    return points;
}

void writeSortedSegmentsToFile(const std::vector<std::pair<Point, Point>>& segments, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& segment : segments) {
            outputFile << segment.first.x << " " << segment.first.y << " " << segment.first.z
                << "; " << segment.second.x << " " << segment.second.y << " " << segment.second.z << std::endl;
        }

        outputFile.close();
    }
    else {
        std::cerr << "Unable to open the output file." << std::endl;
    }
}

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";
    std::vector<Point> points = readPointsFromFile(inputFilename);
    std::vector<std::pair<Point, Point>> segments;
    std::vector<double> lengths;

    for (std::size_t i = 0; i < points.size() - 1; ++i) {
        for (std::size_t j = i + 1; j < points.size(); ++j) {
            segments.push_back({ points[i], points[j] });
            lengths.push_back(calculateDistance(points[i], points[j]));
        }
    }
    std::vector<std::size_t> indices(lengths.size());
    for (std::size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }
    std::sort(indices.begin(), indices.end(), [&lengths](std::size_t i, std::size_t j) {
        return lengths[i] < lengths[j];
        });
    std::vector<std::pair<Point, Point>> sortedSegments;
    for (std::size_t index : indices) {
        sortedSegments.push_back(segments[index]);
    }
    writeSortedSegmentsToFile(sortedSegments, outputFilename);
    return 0;
}