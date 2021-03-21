#include "headerA3.h"

/*
    Takes in a char, and will return 1(true) if the character is one of the specified
    end word chars. It will return 0(false) if it doesn't
*/
int isEndWordChar(char character) {
    char lookFors[] = {" ,.?!;:(){}[]/|\\<>\'\"\n\0\t\r"};

    for (int i = 0; i < strlen(lookFors); i++) {
        if (lookFors[i] == character || character == '\0' || character == '\n' || character == '\t' || character == '\r') {
            printf("%c\n", lookFors[i]);
            if (character == '\0') {
                printf("NULL\n");
            }
            if (character == '\r') {
                printf("RETURN\n");
            }
            if (character == '\n') {
                printf("NEW\n");
            }
            if (character == '\t') {
                printf("TAB\n");
            }
            return 1;
        }
    }

    return 0;
}