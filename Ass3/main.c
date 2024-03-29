#include "headerA3.h"
#include "helper.h"

int main(void) {
    int menuChoice;
    tweet *tweetList;
    tweetList = NULL;

    do {
        // print out the main option menu
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\"\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file \n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");
        //get user choice
        printf("Choose a menu option: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                addNodeToList(&tweetList, createTweet(tweetList));

                break;

            case 2:
                displayTweets(tweetList);

                break;

            case 3:
                searchTweetsByKeyword(tweetList);

                break;

            case 4:
                countStopWords(tweetList);

                break;

            case 5:
                deleteTweet(&tweetList);

                break;

            case 6:
                saveTweetsToFile(tweetList);

                break;

            case 7:
                loadTweetsFromFile(&tweetList);

                break;

            case 8:
                // If 8(exit) is selected, thank the user and the loop will end
                printf("Thank you for using TwitterV2\n");

                break;

            default:
                // If one of the above options is not selected, print a
                // error informing the user that the option in invalid.
                printf("ERROR: %d IS A INVALID MENU CHOICE\n", menuChoice);
                break;
        }
    } while (menuChoice != 8);

    // free memory
    free(tweetList);

    return 0;
}