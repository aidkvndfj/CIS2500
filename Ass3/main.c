#include "headerA3.h"

int main(void) {
    int menuChoice;

    do {
        // print out the main option menu
        printf("Please input a menu choice from 1-8:\n");
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\"\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file \n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");
        //get user choice
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Case %d\n", menuChoice);

                break;

            case 2:
                printf("Case %d\n", menuChoice);

                break;

            case 3:
                printf("Case %d\n", menuChoice);

                break;

            case 4:
                printf("Case %d\n", menuChoice);

                break;

            case 5:
                printf("Case %d\n", menuChoice);

                break;

            case 6:
                printf("Case %d\n", menuChoice);

                break;

            case 7:
                printf("Case %d\n", menuChoice);

                break;

            case 8:
                // If 8(exit) is selected, thank the user and the loop will end
                printf("Thank you for using TwitterV2\n");

                break;

            default:
                // If one of the above options is not slected, print a
                // error informing the user that the option in invalid.
                printf("ERROR: %d IS A INVALID MENU CHOICE\n", menuChoice);
                break;
        }
        printf("------------------------------------\n");
    } while (menuChoice != 8);

    return 0;
}