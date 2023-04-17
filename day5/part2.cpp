#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>
#include <deque>

static constexpr uint8_t STEP = 4;


void printVectorOfDeques(const std::vector<std::deque<char>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Deque " << i + 1 << ":\n";
        for (const auto& elem : vec[i]) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::ifstream file("input.txt");
    std::string line;


    std::vector<std::deque<char>> stacks(9);

    while(std::getline(file, line)) {
        if(line.empty()) {
            break;
        }

        if(std::isdigit(line.at(1))) {
            continue;
        }

        for(size_t i = 1; i < line.size(); i += STEP) {
            uint8_t stackLocation = i / STEP;
            if(std::isalpha(line.at(i))) {
                stacks[stackLocation].push_front(line.at(i));
            }
        }
    }

    while(std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string command;
        int moveCount = 0;
        int stackFrom = 0;
        int stackTo = 0; 

        lineStream >> command >> moveCount >> command >> stackFrom >> command >> stackTo;

        auto start = stacks[stackFrom - 1].end() - moveCount;
        auto end = stacks[stackFrom - 1].end();

        std::vector<int> elementsToMove(start,end);

        for (const auto& elem : elementsToMove) {
            stacks[stackFrom - 1].pop_back();
            stacks[stackTo - 1].push_back(elem);
        }
    }

    for (size_t i = 0; i < stacks.size(); ++i) {
        if (!stacks[i].empty()) {
            std::cout << stacks[i].back();
        }
    }

}