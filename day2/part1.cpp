#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <map>

static constexpr int ALIGN = 'x' - 'a';

static constexpr int DRAW = 3;
static constexpr int WIN = 6;
static constexpr int LOST = 0;

int resultScore(char opp, char me) {
    if(opp == (me - ALIGN)) {
        return DRAW;
    }
    else if(opp == 'A' && me == 'Y' || opp == 'B' && me == 'Z' || opp == 'C' && me == 'X') {
        return WIN;
    }
    else  {
        return LOST;
    }
}

int main() {
    std::ifstream file("input.txt");
    std::string line;

    std::map<char, int> shapeScore{{'A', 1}, {'B', 2}, {'C', 3}, {'X', 1}, {'Y', 2}, {'Z', 3}};
    int totalScore = 0;

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        char oppChar, meChar;
        iss >> oppChar >> meChar;

        totalScore += resultScore(oppChar, meChar) + shapeScore[meChar];
    }

    std::cout << totalScore;

}