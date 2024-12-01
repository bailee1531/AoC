// Advent of Code 2024 Day 1
// Part 1: Sort Location ID lists and get the total difference

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("day1input.txt");
    string lineData = "";

    if (inputFile.is_open()) {
        while(!inputFile.eof()) {
            getline(inputFile, lineData);
        }
        inputFile.close();
    }
    return 0;
}