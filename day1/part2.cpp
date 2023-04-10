#include <iostream>
#include <fstream>
#include <set>
#include <cstdint>


int main() {
    std::ifstream file("input.txt");
    std::set<uint32_t> totalSums = {0, 0, 0};
    uint32_t currentSum = 0;

    if (!file.is_open()) { // Check if the file was opened successfully
        std::cerr << "Error opening file";
    }

    std::string line;
    while (std::getline(file, line)) { 
        if(line.empty()) {
            auto it = totalSums.lower_bound(currentSum);

            if (it != totalSums.begin()) {
                if (totalSums.size() >= 3) {
                    totalSums.erase(totalSums.begin());
                }
                totalSums.insert(currentSum);
            }

            currentSum = 0;
        }
        else {
            currentSum += std::stoi(line);
        }
    }

    uint32_t totalSum = 0;
    for(uint32_t value: totalSums) {
        totalSum += value;
    }

    std::cout << totalSum;
}