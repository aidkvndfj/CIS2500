// #include "headerA4.h"
#include "helper.h"

int main(void) {    
    tweet *tweetHead;
    tweet *tweetTail;
    
    tweet *testNode1;
    tweet *testNode2;
    tweet *testNode3;

    tweetHead = NULL;
    tweetTail = NULL;

    testNode1 = malloc(sizeof(tweet));
    testNode2 = malloc(sizeof(tweet));
    testNode3 = malloc(sizeof(tweet));

    testNode1->id = 420;
    strcpy(testNode1->user, "Eric");
    strcpy(testNode1->text, "This is a test tweet.");
    testNode1->next = NULL;


    testNode2->id = 421;
    strcpy(testNode2->user, "Eric");
    strcpy(testNode2->text, "This is a test tweet.");
    testNode2->next = NULL;


    testNode3->id = 422;
    strcpy(testNode3->user, "Eric");
    strcpy(testNode3->text, "This is a test tweet.");
    testNode3->next = NULL;

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
    enqueue(&tweetHead, &tweetTail, testNode3);
    // enqueue(&tweetHead, &tweetTail, testNode2);
    // enqueue(&tweetHead, &tweetTail, testNode1);

    printf("PRINT\n");
    printQueue(tweetHead);

    // printf("SORT ID\n");
    // sortID(&tweetHead, &tweetTail);

    // printf("PRINT\n");
    // printQueue(tweetHead);


    FreeQueue(tweetHead);
    printf("Done\n");


    return 0;
}