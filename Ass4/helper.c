#include "helper.h"

void InitializeQueue(queue *currQueue) {
    currQueue->count = 0;
    currQueue->front = NULL;
    currQueue->rear = NULL;
}

void FreeQueue(tweet *head) {
    tweet *tempTweet;
    while (head != NULL) {
        tempTweet = head->next;
        free(head);
        head = tempTweet;
    }
}

void InitializeTweet(tweet *currTweet) {
    currTweet->id = 0;
    strcpy(currTweet->user, "");
    strcpy(currTweet->text, "");
    currTweet->next = NULL;
}

tweet* Pop(tweet **head, tweet **tail) {
    tweet *tempHead;
    tweet *returnTweet;

    printf("Set Return\n");
    returnTweet = *tail;

    printf("WHILE\n");
    while (tempHead->next != NULL) {
        printf("WHILE\n");
        tempHead = tempHead->next;
    }
    // while (tempHead->next->next != NULL || tempHead->next != NULL) {
    //     printf("WHILE\n");
    //     tempHead = tempHead->next;
    // }

    printf("REturn\n");
    return returnTweet;
}