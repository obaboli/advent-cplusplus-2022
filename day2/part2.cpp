#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <map>

static constexpr int DRAW = 3;
static constexpr int WIN = 6;
static constexpr int LOST = 0;

char getShape(char opp, char me) {
    if(me == 'Y') {
        return opp;
    }
    else if(me == 'Z') {
        if(opp == 'A') return 'B';
        if(opp == 'B') return 'C';
        else return 'A';
    }
    else {
        if(opp == 'A') return 'C';
        if(opp == 'B') return 'A';
        else return 'B';
    }
}

int main() {
    std::ifstream file("input.txt");
    std::string line;

    std::map<char, int> shapeScore{{'A', 1}, {'B', 2}, {'C', 3}};
    std::map<char, int> resultScore{{'X', LOST}, {'Y', DRAW}, {'Z', WIN}};
    int totalScore = 0;

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        char oppChar, meChar;
        iss >> oppChar >> meChar;

        char meShape = getShape(oppChar, meChar);
        totalScore += resultScore[meChar] + shapeScore[meShape];
    }

    std::cout << totalScore;

}