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
    strcpy(testNode8->user, "Aether");
    strcpy(testNode8->text, "This is a test tweet.8");
    testNode8->next = NULL;

    tweet *testNode9;
    testNode9 = malloc(sizeof(tweet));
    testNode9->id = 429;
    strcpy(testNode9->user, "Paimon");
    strcpy(testNode9->text, "This is a test tweet.9");
    testNode9->next = NULL;

    tweet *testNode10;
    testNode10 = malloc(sizeof(tweet));
    testNode10->id = 4210;
    strcpy(testNode10->user, "Lumine");
    strcpy(testNode10->text, "This is a test tweet.10");
    testNode10->next = NULL;

    tweet *testNode11;
    testNode11 = malloc(sizeof(tweet));
    testNode11->id = 4211;
    strcpy(testNode11->user, "Eric11");
    strcpy(testNode11->text, "This is a test tweet.11");
    testNode11->next = NULL;

    /*
    tweet *testNode12;
    testNode12 = malloc(sizeof(tweet));
    testNode12->id = 4212;
    strcpy(testNode12->user, "Eric12");
    strcpy(testNode12->text, "This is a test tweet.12");
    testNode12->next = NULL;

    tweet *testNode13;
    testNode13 = malloc(sizeof(tweet));
    testNode13->id = 4213;
    strcpy(testNode13->user, "Eric13");
    strcpy(testNode13->text, "This is a test tweet.13");
    testNode13->next = NULL;

    tweet *testNode14;
    testNode14 = malloc(sizeof(tweet));
    testNode14->id = 4214;
    strcpy(testNode14->user, "Eric14");
    strcpy(testNode14->text, "This is a test tweet.14");
    testNode14->next = NULL;

    tweet *testNode15;
    testNode15 = malloc(sizeof(tweet));
    testNode15->id = 4215;
    strcpy(testNode15->user, "Eric15");
    strcpy(testNode15->text, "This is a test tweet.15");
    testNode15->next = NULL;

    tweet *testNode16;
    testNode16 = malloc(sizeof(tweet));
    testNode16->id = 4216;
    strcpy(testNode16->user, "Eric16");
    strcpy(testNode16->text, "This is a test tweet.16");
    testNode16->next = NULL;

    tweet *testNode17;
    testNode17 = malloc(sizeof(tweet));
    testNode17->id = 4217;
    strcpy(testNode17->user, "Eric17");
    strcpy(testNode17->text, "This is a test tweet.17");
    testNode17->next = NULL;

    tweet *testNode18;
    testNode18 = malloc(sizeof(tweet));
    testNode18->id = 4218;
    strcpy(testNode18->user, "Eric18");
    strcpy(testNode18->text, "This is a test tweet.18");
    testNode18->next = NULL;
    */

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nQueue Test 1\n");
    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode3);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nIs Empty Test 1\n");
    printf("ISEMPTY\n");
    printf("Is empty expected: 0, Actual: %d", isEmpty(tweetHead));

    printf("\nQueue Test 2\n");
    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode1);
    enqueue(&tweetHead, &tweetTail, testNode2);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nDequeue Test 1\n");
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nDequeue Test 2\n");
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nDequeue Test 3\n");
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nIs Empty Test 2\n");
    printf("ISEMPTY\n");
    printf("Is empty expected: 1, Actual: %d", isEmpty(tweetHead));

    printf("\nQueue Test 3\n");
    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode5);
    enqueue(&tweetHead, &tweetTail, testNode6);
    enqueue(&tweetHead, &tweetTail, testNode4);
    enqueue(&tweetHead, &tweetTail, testNode7);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nReverse Test 1\n");
    printf("REVERSE\n");
    reverse(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nSort ID Test 1.\n");
    printf("SORT ID\n");
    sortID(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nSort ID Test 2.\n");
    printf("SORT ID\n");
    sortID(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nReverse Test 2\n");
    printf("REVERSE\n");
    reverse(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nSort ID Test 3.\n");
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);

    printf("SORT ID\n");
    sortID(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nIs Empty Test 3\n");
    printf("ISEMPTY\n");
    printf("Is empty expected: 1, Actual: %d", isEmpty(tweetHead));

    printf("\nSort Name Test 1\n");
    printf("QUEUE\n");
    enqueue(&tweetHead, &tweetTail, testNode9);
    enqueue(&tweetHead, &tweetTail, testNode8);
    enqueue(&tweetHead, &tweetTail, testNode10);
    enqueue(&tweetHead, &tweetTail, testNode11);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("SORT NAME\n");
    sortUsername(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nSort Name Test 2.\n");
    printf("SORT NAME\n");
    sortUsername(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nReverse Test 3\n");
    printf("REVERSE\n");
    reverse(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    printf("\nSort Name Test 3.\n");
    printf("DEQUEUE\n");
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);
    dequeue(&tweetHead, &tweetTail);

    printf("SORT NAME\n");
    sortUsername(&tweetHead, &tweetTail);

    printf("PRINT\n");
    printQueue(tweetHead);

    FreeQueue(tweetHead);
    printf("Completed Program Testing\n");

    return 0;
}