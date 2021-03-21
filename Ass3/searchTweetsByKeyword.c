#include "headerA3.h"

int searchTweetsByKeyword(tweet* tweetList) {
    char* keyword;
    char currChar;
    int length;
    int i;
    int j;
    int wordIsThere;
    int success;
    tweet* tempTweetList;

    tempTweetList = tweetList;
    length = 0;
    success = 0;

    //make sure tweet list isn't empty
    if (tweetList == NULL) {
        printf("ERROR: tweet list empty\n");
        return 0;
    }

    keyword = malloc(sizeof(char));
    // keyword = NULL;

    // Get keyword
    fflush(stdin);
    printf("Enter a keyword to search: ");
    fgetc(stdin);
    scanf("%c", &currChar);
    keyword[length] = currChar;

    // loop until newchar, add chars to string
    while (currChar != '\n') {
        length++;
        keyword = realloc(keyword, sizeof(char) * (length + 1));
        scanf("%c", &currChar);
        keyword[length] = currChar;
    }
    keyword[length] = '\0';

    // loop until break
    while (1) {
        // loop until the end of the tweets text
        for (i = 0; i < strlen(tempTweetList->text); i++) {
            // if the current letter is the same as the first letter in the keyword
            if (tolower(tempTweetList->text[i]) == tolower(keyword[0])) {
                // set that they word is there to 1, and loop through the next length chars to check the rest of the word.
                wordIsThere = 1;
                for (j = 0; j < length; j++) {
                    // if at any point the characters don't match up, set word is there to 0 meaning the word is not there
                    if (tolower(tempTweetList->text[i + j]) != tolower(keyword[0 + j])) {
                        wordIsThere = 0;
                        break;
                    }
                }
                // if at the end of the loop the word is there, print the sentence
                if (wordIsThere == 1) {
                    printf("Match found for '%s': %s wrote: \"%s\"\n", keyword, tempTweetList->user, tempTweetList->text);
                    success = 1;
                    break;
                }
            }
        }

        // if the next tweet is null(doesn't exist) then break, otherwise move to next tweet.
        if (tempTweetList->next == NULL) {
            break;
        }
        else {
            tempTweetList = tempTweetList->next;
        }
    }

    free(keyword);
    return success;
}