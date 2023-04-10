#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>


int main() {
    std::ifstream file("input.txt");
    uint32_t totalSum = 0;

    uint32_t currentSum = 0;

    if (!file.is_open()) { // Check if the file was opened successfully
        std::cerr << "Error opening file";
    }

    std::string line;
    while (std::getline(file, line)) { 
        if(line.empty()) {
            if(currentSum > totalSum) {
                totalSum = currentSum;
            }
            currentSum = 0;
        }
        else {
            currentSum += std::stoi(line);
        }
    }

    std::cout << totalSum;
}