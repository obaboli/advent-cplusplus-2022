#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cstdint>

char getError(const std::string& str1, const std::string& str2) {
    std::unordered_set<char> set1(str1.begin(), str1.end());
    std::unordered_set<char> set2(str2.begin(), str2.end());

    for(char c: set1) {
        if(set2.find(c) != set2.end()) {
            return c;
        }
    }

    //Error
    return '0';
}

uint32_t getPriority(char item) {
    if (std::islower(item)) {
        return item - 'a' + 1;
    } else if (std::isupper(item)) {
        return item - 'A' + 27;
    } else {
        //Error
        return 0; 
    }
}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::string firstHalf;
    std::string secondHalf;  
    uint32_t totalScore = 0;

    while(std::getline(file, line)) {
        size_t middleIndex = line.length() / 2;

        firstHalf = line.substr(0, middleIndex);
        secondHalf = line.substr(middleIndex);

        char error = getError(firstHalf, secondHalf);

        if(error == '0') {
            std::cerr << "Couldn't find error" << std::endl;
            exit(1);
        }

        uint32_t priority = getPriority(error);

         if(priority == 0) {
            std::cerr << "Not valid char for score" << std::endl;
            exit(1);
        }

        totalScore += priority;
    }

    std::cout << totalScore;
}