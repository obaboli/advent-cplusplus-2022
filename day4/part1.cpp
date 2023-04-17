#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>

bool isContained(uint32_t lower1, uint32_t upper1, uint32_t lower2, uint32_t upper2) {
    return (lower1 >= lower2 && upper1 <= upper2) || (lower2 >= lower1 && upper2 <= upper1);
}


int main() {
    std::ifstream file("input.txt");
    std::string line;
    uint32_t totalScore = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        uint32_t a, b, c, d;
        char hyphen1, comma, hyphen2;

        if (iss >> a >> hyphen1 >> b >> comma >> c >> hyphen2 >> d) {
            if(isContained(a, b, c, d)){
                totalScore++;
            }
        }
    }

    std::cout << totalScore;
}