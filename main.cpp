#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void fileStatistics(const char* fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "Unable to open file\n";
        return;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    char ch;

    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (isdigit(ch)) {
            digitCount++;
        }
        if (ch == '\n') {
            lineCount++;
        }
        charCount++;
    }

    inputFile.close();

    ofstream outputFile("statistics.txt");
    if (!outputFile.is_open()) {
        cerr << "Unable to create statistics file\n";
        return;
    }

    outputFile << "Number of characters: " << charCount << "\n";
    outputFile << "Number of lines: " << lineCount << "\n";
    outputFile << "Number of vowels: " << vowelCount << "\n";
    outputFile << "Number of consonants: " << consonantCount << "\n";
    outputFile << "Number of digits: " << digitCount << "\n";

    outputFile.close();
}

int main() {
    fileStatistics("input.txt");
    return 0;
}
