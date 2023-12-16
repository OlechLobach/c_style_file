#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct WordData {
    char word[100];
    int length;
};

void addWordToFile(const char* filename, const WordData& data) {
    FILE* file = fopen(filename, "a");

    if (!file) {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "%s ", data.word);

    fclose(file);
}

int main() {
    FILE* outputFile = fopen("output.txt", "w");

    if (!outputFile) {
        printf("Error opening output file\n");
        return 1;
    }

    const char* wordsToAdd[] = { "Butterfly", "Description", "Subscribe", "Company", "Compilation", "Subscribers", "smartphone", "wallpapers", "magazines" };
    const int numWords = sizeof(wordsToAdd) / sizeof(wordsToAdd[0]);

    WordData wordData;

    for (int i = 0; i < numWords; ++i) {
        strcpy(wordData.word, wordsToAdd[i]);
        wordData.length = strlen(wordData.word);
        if (wordData.length >= 7) {
            fprintf(outputFile, "%s ", wordData.word);
            addWordToFile("output.txt", wordData);
        }
    }

    fclose(outputFile);

    return 0;
}
