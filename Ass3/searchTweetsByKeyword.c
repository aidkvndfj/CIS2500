#include "headerA3.h"

int searchTweetsByKeyword(tweet* tweetList) {
    char *keyword;
    char currChar;
    int length;
    int i;
    int j;
    int wordIsThere;
    tweet* tempTweetList;

    tempTweetList = tweetList;
    length = 0;

    keyword = malloc(sizeof(char));
    // keyword = NULL;

    // Get keyword
    fflush((stdin));
    printf("Enter a keyword to search: ");
    scanf("%c", &currChar);
    keyword[length] = currChar;

    // loop untill newchar, add chars to string
    while (currChar != '\n') {
        length++;
        keyword = realloc(keyword, sizeof(char) * (length + 1));
        scanf("%c", &currChar);
        keyword[length] = currChar;
    }
    keyword[length] = '\0';

    // make sure the list isn't empty
    if (tempTweetList != NULL) {
        // loop until break
        while (1) {
            // loop untill the end of the tweets text
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
                        break;
                    }
                }
            }   

            // if the next tweet is null(doesn't exsist) the break, otherwise move to next tweet.
            if (tempTweetList->next == NULL) {
                break;
            }
            else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    free(keyword);
    return 0;
}