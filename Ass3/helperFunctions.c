#include "headerA3.h"

/*
    Takes in a char, and will return 1(true) if the character is one of the specified
    end word chars. It will return 0(false) if it doesn't
*/
int isEndWordChar(char character) {
    if (character == ' ' || character == ',' || character == '\n' || character == '\0' || character == '.') {
        return 1;
    }

    return 0;
}