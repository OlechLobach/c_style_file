#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void compareFiles(const char* file1, const char* file2) {
   ifstream input1(file1);
    ifstream input2(file2);

    if (!input1.is_open() || !input2.is_open()) {
        cerr << "Unable to open files\n";
        return;
    }

    char line1[255], line2[255];
    int lineNum = 1;

    while (input1.getline(line1, 255) && input2.getline(line2, 255)) {
        if (strcmp(line1, line2) != 0) {
            cout << "Mismatch at line " << lineNum << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
        }
        lineNum++;
    }

    input1.close();
    input2.close();
}

int main() {
    compareFiles("file1.txt", "file2.txt");
    return 0;
}
