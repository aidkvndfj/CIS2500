#include "helper.h"

void sortID(tweet** head, tweet** tail) {
    //Using Bubble Sort
    tweet *tempTweet;
    tweet *tempHead;
    int isSorted;

    if (isEmpty(*head) || *head == *tail) {
        printf("List is empty, or only has 1 value. Nothing to sort\n");
        return;
    }

    tempHead = *head;

    while(1) {
        if (tempHead->id > tempHead->next->id) {
            if (tempHead == (*head)) {
                tempTweet = (*head);
                tempTweet->next = tempHead->next->next;

                (*head) = tempHead->next;
                (*head)->next = tempTweet;

            } else {
                tempTweet = tempHead;
                tempTweet->next = tempHead->next->next;

                tempHead = tempHead->next;
                tempHead->next = tempTweet;
            }
            isSorted = 0;
        }   

        //if at end of queue
        if (tempHead->next == NULL) {
            tempHead = *head;
            printf("is Sorted: %d\n", isSorted);
            if (isSorted == 1) {
                break;
            }
            isSorted = 1;
        } else {
            tempHead = tempHead->next;
        }
    }
}

void reverse(tweet** head, tweet** tail) {
    tweet *tempTweet;

    tempTweet = *head;
    while (tempTweet != NULL) {
        
    }
}

void sortUsername(tweet** head, tweet** tail) {

}

/* reverse
(tail)1->2->3(head)
(tail)3->2->1(head)

*/
