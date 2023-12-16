#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<iostream>

int main() {
    FILE* sourceFile, * destinationFile;
    char buffer[1000];  

    
    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        perror("Error open file");
        return -1;
    }

   
    destinationFile = fopen("destination.txt", "w");
    if (destinationFile == NULL) {
        perror("Error open file אשך writing");
        return -1;
    }

   
    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL) {
        fputs(buffer, destinationFile);
    }

    
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}