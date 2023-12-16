#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void addSeparatorLine(const char* sourceFile, const char* destinationFile) {
    ifstream inputFile(sourceFile);
    ofstream outputFile(destinationFile, ios_base::app);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Unable to open file\n";
        return;
    }

    char line[255];
    char lastLine[255];
    bool found = false;

    while (inputFile.getline(line, 255)) {
        if (strpbrk(line, " ") == nullptr) {
            found = true;
            strcpy(lastLine, line);
        }
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    while (inputFile.getline(line, 255)) {
        outputFile << line << "\n";
    }

    if (found) {
        outputFile << "------------\n";
    }
    else {
        outputFile << lastLine << "\n";
        outputFile << "------------\n";
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    addSeparatorLine("input.txt", "output_with_separator.txt");
    return 0;
}
