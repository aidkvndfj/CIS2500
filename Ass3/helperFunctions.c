#include "headerA3.h"

/*
    Takes in a char, and will return 1(true) if the character is one of the specified
    end word chars. It will return 0(false) if it doesn't
*/
int isEndWordChar(char character) {
    char lookFors[] = {" ,.?!;:(){}[]/|\\<>\'\"\n\0\t\r"};

    for (int i = 0; i < strlen(lookFors); i++) {
        if (lookFors[i] == character) {
            return 1;
        }
    }

    return 0;
}