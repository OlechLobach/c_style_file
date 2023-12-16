#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void reverseLines(const char* sourceFile, const char* destinationFile) {
    ifstream inputFile(sourceFile);
    ofstream outputFile(destinationFile);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Unable to open file\n";
        return;
    }

    const int maxLines = 1000;
    char lines[maxLines][255];
    int lineNumber = 0;

    while (inputFile.getline(lines[lineNumber], 255)) {
        lineNumber++;
    }

    
    for (int i = lineNumber - 1; i >= 0; i--) {
        outputFile << lines[i] << "\n";
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    reverseLines("input.txt", "reversed_output.txt");
    return 0;
}
