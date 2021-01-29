#include "main.h"

int main(int argc, char* argv[]) {
    firstChars(argv[1], atoi(argv[2]));
    printf("\n-----------------------------------------\n");

    lastChars(argv[1], atoi(argv[2]));

    return 0;
}

void firstChars(char* filename, int howMany) {
    FILE* inFile = NULL;
    inFile = fopen(filename, "rb");

    char buffer[100];
    int charsRead;

    fseek(inFile, 0, SEEK_SET);
    charsRead = fread(buffer, sizeof(char), howMany, inFile);
    for (int i = 0; i < charsRead; i++) {
        printf("%c", buffer[i]);
    }
}

void lastChars(char* filename, int howMany) {
    FILE* inFile = NULL;
    inFile = fopen(filename, "rb");

    char buffer[100];
    int charsRead;

    fseek(inFile, -howMany, SEEK_END);
    charsRead = fread(buffer, sizeof(char), howMany, inFile);
    for (int i = 0; i < charsRead; i++) {
        printf("%c", buffer[i]);
    }
}