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
    regex rgxWord("one|two|three|four|five|six|seven|eight|nine");
    smatch firstNum;    // Stores matches for first regex
    smatch secondNum;   // Stores matches for second regex
    smatch wordNum;
    string strArr1[1];  // Temp array to store first digit found by regex
    string strArr2[1];  // Temp array to store second digit found by regex
    int sum = 0;        // Sum of integers
    int i = 0;          // Iterator

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            getline(inputFile, lineData);   // Gets string of data

            regex_search(lineData, wordNum, rgxWord);
            regex_search(lineData, firstNum, rgxFirst);     // Searches for first digit
            if (wordNum.position() < firstNum.position()) { // Checks if number in word form is before a digit
                if (wordNum[0] == "one") {                  // If number in word form is first, convert to digit string
                    strArr1[i] = "1";
                }
                else if (wordNum[0] == "two") {
                    strArr1[i] = "2";
                }
                else if (wordNum[0] == "three") {
                    strArr1[i] = "3";
                }
                else if (wordNum[0] == "four") {
                    strArr1[i] = "4";
                }
                else if (wordNum[0] == "five") {
                    strArr1[i] = "5";
                }
                else if (wordNum[0] == "six") {
                    strArr1[i] = "6";
                }
                else if (wordNum[0] == "seven") {
                    strArr1[i] = "7";
                }
                else if (wordNum[0] == "eight") {
                    strArr1[i] = "8";
                }
                else if (wordNum[0] == "nine") {
                    strArr1[i] = "9";
                }
                lineData = wordNum.suffix();    // Sets lineData to substring after match found
            }
            else {
                strArr1[i] = firstNum[0];       // Stores match into temp array
                lineData = firstNum.suffix();   // Sets lineData to substring after match found
            }

            regex_search(lineData, wordNum, rgxWord);
            regex_search(lineData, secondNum, rgxSecond);   // Searches substring for last digit

            if (wordNum.position() > secondNum.position()) { // Checks if number in word form comes after digit
                if (wordNum[0] == "one") {                  // If number in word form is last, convert to digit string
                    strArr2[i] = "1";
                }
                else if (wordNum[0] == "two") {
                    strArr2[i] = "2";
                }
                else if (wordNum[0] == "three") {
                    strArr2[i] = "3";
                }
                else if (wordNum[0] == "four") {
                    strArr2[i] = "4";
                }
                else if (wordNum[0] == "five") {
                    strArr2[i] = "5";
                }
                else if (wordNum[0] == "six") {
                    strArr2[i] = "6";
                }
                else if (wordNum[0] == "seven") {
                    strArr2[i] = "7";
                }
                else if (wordNum[0] == "eight") {
                    strArr2[i] = "8";
                }
                else if (wordNum[0] == "nine") {
                    strArr2[i] = "9";
                }
                else if (strArr2[i] == "") {
                    strArr2[i] = strArr1[i];
                }
            }
            else {
                strArr2[i] = secondNum[0];      // Stores match into temp array
            }

            cout << strArr1[i] << strArr2[i] << endl;
            //sum += stoi(strArr1[i] + strArr2[i]);    // Concatenate first and second digit strings, then convert to int and add to sum
        }
        inputFile.close();
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
