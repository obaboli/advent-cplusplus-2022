#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <cstdint>
#include <unordered_set>

static constexpr uint8_t WINDOW_SIZE = 14;

bool checkUnique(const std::queue<char>& q) {
    std::queue<char> temp_queue = q;
    std::unordered_set<char> char_set;

    while (!temp_queue.empty()) {
        char current_char = temp_queue.front();
        if (char_set.find(current_char) != char_set.end()) {
            return false;
        }
        char_set.insert(current_char);
        temp_queue.pop();
    }

    return true;
}

void printQueue(std::queue<char> q) {
    while (!q.empty()) {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::ifstream file("input.txt");
    std::stringstream dataStream;
    std::string line;

    while (std::getline(file, line)) {
        dataStream << line;
    }

    std::string data = dataStream.str();

    std::queue<char> order;

    for(size_t i = 0; i < data.length(); i++){
        order.push(data.at(i));

        if(order.size() == WINDOW_SIZE) {
            if(checkUnique(order)) {
                std::cout << i + 1;
                break;
            }
            order.pop();
        }
    }

}