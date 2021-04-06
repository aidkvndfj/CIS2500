// #include "headerA4.h"
#include "helper.h"

int main(void) {    
    tweet *tweetHead;
    tweet *tweetTail;

    tweetHead = NULL;
    tweetTail = NULL;

    tweet *testNode1;
    testNode1 = malloc(sizeof(tweet));
    testNode1->id = 421;
    strcpy(testNode1->user, "Eric1");
    strcpy(testNode1->text, "This is a test tweet.1");
    testNode1->next = NULL;

    tweet *testNode2;
    testNode2 = malloc(sizeof(tweet));
    testNode2->id = 422;
    strcpy(testNode2->user, "Eric2");
    strcpy(testNode2->text, "This is a test tweet.2");
    testNode2->next = NULL;

    tweet *testNode3;
    testNode3 = malloc(sizeof(tweet));
    testNode3->id = 423;
    strcpy(testNode3->user, "Eric3");
    strcpy(testNode3->text, "This is a test tweet.3");
    testNode3->next = NULL;

    tweet *testNode4;
    testNode4 = malloc(sizeof(tweet));
    testNode4->id = 424;
    strcpy(testNode4->user, "Eric4");
    strcpy(testNode4->text, "This is a test tweet.4");
    testNode4->next = NULL;

    tweet *testNode5;
    testNode5 = malloc(sizeof(tweet));
    testNode5->id = 425;
    strcpy(testNode5->user, "Eric5");
    strcpy(testNode5->text, "This is a test tweet.5");
    testNode5->next = NULL;

    tweet *testNode6;
    testNode6 = malloc(sizeof(tweet));
    testNode6->id = 426;
    strcpy(testNode6->user, "Eric6");
    strcpy(testNode6->text, "This is a test tweet.6");
    testNode6->next = NULL;

    tweet *testNode7;
    testNode7 = malloc(sizeof(tweet));
    testNode7->id = 427;
    strcpy(testNode7->user, "Eric7");
    strcpy(testNode7->text, "This is a test tweet.7");
    testNode7->next = NULL;

    tweet *testNode8;
    testNode8 = malloc(sizeof(tweet));
    testNode8->id = 428;
    strcpy(testNode8->user, "Eric8");
    strcpy(testNode8->text, "This is a test tweet.8");
    testNode8->next = NULL;

    tweet *testNode9;
    testNode9 = malloc(sizeof(tweet));
    testNode9->id = 429;
    strcpy(testNode9->user, "Eric9");
    strcpy(testNode9->text, "This is a test tweet.9");
    testNode9->next = NULL;

    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode3);
    enqueue(&tweetHead, &tweetTail, testNode2);
    enqueue(&tweetHead, &tweetTail, testNode1);
    
    printf("PRINT\n");
    printQueue(tweetHead);
    
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    
    printf("PRINT\n");
    printQueue(tweetHead);
    
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);
    
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    
    printf("PRINT\n");
    printQueue(tweetHead);
    
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    
    printf("PRINT\n");
    printQueue(tweetHead);


    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode9);
    enqueue(&tweetHead, &tweetTail, testNode7);
    enqueue(&tweetHead, &tweetTail, testNode8);
    enqueue(&tweetHead, &tweetTail, testNode6);
    enqueue(&tweetHead, &tweetTail, testNode4);
    enqueue(&tweetHead, &tweetTail, testNode5);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("SORT NAME\n");
    sortUsername(&tweetHead, &tweetTail);
    // printf("SORT ID\n");
    // sortID(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("REVERSE\n");
    reverse(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    FreeQueue(tweetHead);
    // printf("Done\n");


    return 0;
}