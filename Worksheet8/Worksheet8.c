#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizzaMaker
{
    char topping[30];
    struct pizzaMaker * next;
};

typedef struct pizzaMaker pizzaNode;    

void addTopping(pizzaNode * pizzaHead);
void displayAllToppings(pizzaNode *pizzaHead);
void displayAllToppingsR(pizzaNode *pizzaHead);

int main(void) {
    // create nodes we need to use
    pizzaNode *pizzaHead, *pizzaPtr, *pizzaTemp;

    //define head as null
    pizzaHead = malloc(sizeof(pizzaNode));
    pizzaHead = NULL;
    
    //crate node 1
    pizzaPtr = malloc(sizeof(pizzaNode));
    strcpy(pizzaPtr->topping, "Onion");
    pizzaPtr->next = NULL;
    // since it's node 1, set the head to the node
    pizzaHead = pizzaPtr;
    pizzaTemp = pizzaHead;

    //create node 2
    pizzaPtr = malloc(sizeof(pizzaNode));
    strcpy(pizzaPtr->topping, "Olives");
    pizzaPtr->next = NULL;
    //Find end of list, and add new node
    while (pizzaTemp->next != NULL) {
        pizzaTemp = pizzaTemp->next;
    }
    pizzaTemp->next = pizzaPtr;
    pizzaTemp = pizzaHead;

    //create node 3
    pizzaPtr = malloc(sizeof(pizzaNode));
    strcpy(pizzaPtr->topping, "Jalapeno");
    pizzaPtr->next = NULL;
    //Find end of list, and add new node
    while (pizzaTemp->next != NULL) {
        pizzaTemp = pizzaTemp->next;
    }
    pizzaTemp->next = pizzaPtr;
    pizzaTemp = pizzaHead;

    addTopping(pizzaHead);

    displayAllToppings(pizzaHead);
    printf("\n");
    displayAllToppingsR(pizzaHead);

    return 0;
}

void addTopping(pizzaNode * pizzaHead) {
    pizzaNode *newTopping, *tempTopping;

    tempTopping = pizzaHead;

    newTopping = malloc(sizeof(pizzaNode));
    printf("Please type out which topping you would like to add: ");
    scanf("%s", newTopping->topping);
    newTopping->next = NULL;

    if (tempTopping == NULL) {
        pizzaHead = newTopping;
    } else {
        while(tempTopping->next != NULL) {
            tempTopping = tempTopping->next;
        }
        tempTopping->next = newTopping;
    }
}

void displayAllToppings(pizzaNode *pizzaHead) {
    while (pizzaHead != NULL) {
        printf("Topping: %s\n", pizzaHead->topping);
        pizzaHead = pizzaHead->next;
    }
}

void displayAllToppingsR(pizzaNode *pizzaHead) {
    if (pizzaHead != NULL) {
        printf("topping: %s\n", pizzaHead->topping);
        displayAllToppingsR(pizzaHead->next);
    }
}