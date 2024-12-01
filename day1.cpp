#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("day1input.txt");    // Input file
    string lineData = "";                   // Data to store strings from file
    regex rgxFirst("[0-9]");                // Find first digit
    regex rgxSecond("[0-9](?!.*[0-9])");    // Find last digit in string
    smatch firstNum;    // Stores matches for first regex
    smatch secondNum;   // Stores matches for second regex
    string strArr1[1];  // Temp array to store first digit found by regex
    string strArr2[1];  // Temp array to store second digit found by regex
    int sum = 0;        // Sum of integers
    int i = 0;          // Iterator

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            getline(inputFile, lineData);   // Gets string of data

            regex_search(lineData, firstNum, rgxFirst);     // Searches for first digit
            strArr1[i] = firstNum[0];       // Stores match into temp array
            lineData = firstNum.suffix();   // Sets lineData to substring after match found

            regex_search(lineData, secondNum, rgxSecond);   // Searches substring for last digit
            strArr2[i] = secondNum[0];      // Stores match into temp array

            if (strArr2[i] == "") {
                strArr2[i] = strArr1[i];    // If there is only one digit, then duplicate first digit
            }

            sum += stoi(strArr1[i] + strArr2[i]);    // Concatenate first and second digit strings, then convert to int and add to sum
        }
        inputFile.close();
    }
    cout << "Sum: " << sum << endl;
    return 0;
}