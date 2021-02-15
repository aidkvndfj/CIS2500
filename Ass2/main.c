#include "fleschIndex.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("ERROR | USAGE: ./fleschIndex <filename>.\n");
        return 1;
    }

    // what is the max filename size?
    char filename[] = argv[1];

    return 0;
}