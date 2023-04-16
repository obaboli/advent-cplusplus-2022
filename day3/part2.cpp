#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cstdint>
#include <vector>

char getError(const std::string& str1, const std::string& str2, const std::string& str3) {
    std::unordered_set<char> set1(str1.begin(), str1.end());
    std::unordered_set<char> set2(str2.begin(), str2.end());
    std::unordered_set<char> set3(str3.begin(), str3.end());

    for(char c: set1) {
        if(set2.find(c) != set2.end() && set3.find(c) != set3.end()) {
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
    std::vector<std::string> lines(3); 
    uint32_t totalScore = 0;  
    bool error = false;  

    while(true) {
        for (uint8_t i = 0; i < 3; i++){
            if(!std::getline(file, lines[i])) {
                error = true;
                break;
            }
        }

        if(error) {
            break;
        }

        char badge = getError(lines[0], lines[1], lines[2]);

        if(badge == '0') {
            std::cerr << "Couldn't find error" << std::endl;
            exit(1);
        }

        uint32_t priority = getPriority(badge);

         if(priority == 0) {
            std::cerr << "Not valid char for score" << std::endl;
            exit(1);
        }

        totalScore += priority;
    }

    std::cout << totalScore;
}