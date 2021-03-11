#include "headerA3.h"

int searchTweetsByKeyword(tweet* tweetList) {
    char keyword[20];
    int length;
    int i;
    int j;
    int wordIsThere;
    tweet* tempTweetList;

    tempTweetList = tweetList;

    printf("Enter a keyword to search: ");
    scanf("%s", keyword);

    length = strlen(keyword);

    if (tempTweetList != NULL) {
        while (1) {
            for (i = 0; i < strlen(tempTweetList->text); i++) {
                if (tolower(tempTweetList->text[i]) == tolower(keyword[0])) {
                    wordIsThere = 1;
                    for (j = 0; j < length; j++) {
                        if (tolower(tempTweetList->text[i + j]) != tolower(keyword[0 + j])) {
                            wordIsThere = 0;
                            break;
                        }
                    }
                    if (wordIsThere == 1) {
                        printf("Match found for '%s': %s wrote: \"%s\"\n", keyword, tempTweetList->user, tempTweetList->text);
                        break;
                    }
                }
            }

            if (tempTweetList->next == NULL) {
                break;
            }
            else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    return 0;
}