#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <vector>

void print_grid(const std::vector<std::vector<uint32_t> >& grid) {
    for(size_t i = 0; i < grid.size(); i++) {
        for(size_t j = 0; j < grid[i].size(); j++) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


bool check_neighbors_right(const std::vector<std::vector<uint32_t> >& grid, uint32_t i, uint32_t j) {
    for(size_t k = j + 1; k < grid[i].size(); k++) {
        if(grid[i][k] >= grid [i][j]) {
            return false;
        }
    }

    return true;
}

bool check_neighbors_left(const std::vector<std::vector<uint32_t> >& grid, uint32_t i, uint32_t j) {
    for(int k = j - 1; k >= 0 ; k--) {
        if(grid[i][k] >= grid [i][j]) {
            return false;
        }
    }

    return true;
}

bool check_neighbors_up(const std::vector<std::vector<uint32_t> >& grid, uint32_t i, uint32_t j) {
    for(int k = i - 1; k >= 0 ; k--) {
        if(grid[k][j] >= grid [i][j]) {
            return false;
        }
    }

    return true;
}

bool check_neighbors_down(const std::vector<std::vector<uint32_t> >& grid, uint32_t i, uint32_t j) {
    for(size_t k = i + 1; k < grid.size() ; k++) {
        if(grid[k][j] >= grid [i][j]) {
            return false;
        }
    }

    return true;
}


int main() { 

    std::ifstream file("input.txt");
    std::string line;

    std::vector <std::vector<uint32_t> > grid;

    uint32_t y_count = 0;
    uint32_t x_count = 0;

    uint32_t inner_count = 0;

    while(std::getline(file, line)) {
        std::vector<uint32_t> row;
        x_count = 0;
        for(size_t i = 0; i < line.length(); i++) {
            row.push_back(line.at(i) - '0');
            x_count++;
        }

        y_count++;
        grid.push_back(row);
    }

    for(size_t i = 1; i < grid.size() - 1; i++) {
        for(size_t j = 1; j < grid[i].size() - 1; j++) {
            if(check_neighbors_right(grid, i, j)) {
                inner_count++;
            }
            else if(check_neighbors_left(grid, i, j)) {
                inner_count++;
            }
            else if(check_neighbors_up(grid, i, j)) {
                inner_count++;
            }
            else if(check_neighbors_down(grid, i ,j)) {
                inner_count++;
            }
        }
    }

    uint32_t grid_count = (x_count * y_count) - ((x_count - 2) * (y_count - 2));
    std::cout << inner_count << " " << grid_count << std::endl;

    return 0;
}