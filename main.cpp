#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void caesarCipher(const char* inputFile, const char* outputFile, int shift) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Unable to open files\n";
        return;
    }

    char ch;
    while (input.get(ch)) {
        if (isalpha(ch)) {
            char shiftedChar = islower(ch) ? 'a' + (ch - 'a' + shift) % 26 : 'A' + (ch - 'A' + shift) % 26;
            output << shiftedChar;
        }
        else {
            output << ch;
        }
    }

    input.close();
    output.close();
}

int main() {
    caesarCipher("input.txt", "output_cipher.txt", 3); 
    return 0;
}
