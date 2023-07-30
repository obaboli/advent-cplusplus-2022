#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <vector>
#include <limits>

std::size_t directorySizeClosest = std::numeric_limits<std::size_t>::max();;
std::size_t updateSpaceNeeded = 30000000;
std::size_t maxSpace = 70000000;

struct Directory {
    std::string name;
    std::vector<Directory*> subDirectory;
    Directory* parent;
    std::size_t size;
    std::size_t totalSize;

    Directory(const std::string& n, Directory* p) : name(n), parent(p), size(0) {}
};

Directory* addSubdirectory(Directory* parent, const std::string& name) {
    Directory* current = new Directory(name, parent); 
    parent->subDirectory.push_back(current); 
    return current;
}

void addFileSize(Directory* directory, std::size_t size) {
    directory->size += size;
}

void updateTotalSize(Directory* directory) {
    directory->totalSize = directory->size;
    for (Directory* subdirectory : directory->subDirectory) {
        updateTotalSize(subdirectory);
        directory->totalSize += subdirectory->totalSize;
    }
}

void findDirectorySize(Directory* directory, std::size_t sizeNeeded, int depth = 0) {
    if(directory->totalSize > sizeNeeded && directory->totalSize < directorySizeClosest) {
        directorySizeClosest = directory->totalSize;
       // std::cout << directorySizeClosest << std::endl;
    }

    for (Directory* current : directory->subDirectory) {
        findDirectorySize(current, sizeNeeded, depth + 1);
    }
}

void printDirectory(Directory* directory,  int depth = 0) {
    std::cout << std::string(depth, '-') << directory->name << " " << directory->totalSize << " " << directory->size << std::endl;

    for (Directory* current : directory->subDirectory) {
        printDirectory(current, depth + 1);
    }
}

int main() {
    std::ifstream file("input.txt");
    std::string line;

    // Part 1
    Directory* rootDir =  new Directory("/", nullptr);
    Directory* currentDir =  rootDir;

    while(std::getline(file, line)) {
        if(line.front() == '$') {
            if(line.substr(2,2) == "cd") {
                if(line.substr(5) == "/") {
                    //skip
                }
                if(line.substr(5) == "..") {
                    currentDir = currentDir->parent;
                }
                else {
                    std::string directoryName = line.substr(5);
                    currentDir = addSubdirectory(currentDir, directoryName);
                }
            }
            else if(line.substr(2,2) == "ls") {
                //skip
            }
        }
        else {
            if(line.substr(0,3) == "dir") {
                //skip
            }
            else {
                std::size_t space_pos = line.find(' ');
                std::string fileSize = line.substr(0, space_pos);
                addFileSize(currentDir, std::stoi(fileSize));
            }
        }
    }

    updateTotalSize(rootDir);

    std::size_t sizeNeeded = updateSpaceNeeded  - ( maxSpace - rootDir->totalSize);
    findDirectorySize(rootDir, sizeNeeded);

    std::cout << sizeNeeded << " " << directorySizeClosest << std::endl;


    return 0;
}