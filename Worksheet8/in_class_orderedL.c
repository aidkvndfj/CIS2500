#include <stdio.h>
#include <stdlib.h>

int main () {
    
    struct data {
        int num; /* data stored in the node  */
        struct data *next; /* pointer to the next node */
    };
    typedef struct data datatype;
    
    datatype *head, *ptr, *temp, *tempNode, *tempPtr;
    
    int i;
    head = ptr = NULL;
    for ( i=0; i<3; i++ ) {      // add at the end
        
        temp = head;
        
        ptr = malloc(sizeof(datatype));     // create a new node
        ptr->num = i*10;
        ptr->next = NULL;
        
        if (temp == NULL) {        // set the head
            head = ptr;
        }
        else {
            while (temp->next != NULL) {   // traverse to the last node
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    
    ptr = head;
    while ( ptr != NULL ) {
        printf ( "%d\n", ptr->num );
        ptr = ptr->next;
    }
    

    // create the node
    tempNode = malloc (sizeof (datatype));
    
    tempNode -> num = -25;
    tempNode -> next = NULL;
    
    // start at the bhead of the linked list
    ptr = head;
    
    // if the new node is to be inserted before the first node 
    // note that head changes 
    
    if (tempNode -> num < ptr -> num) {
       tempNode -> next = head;
       head = tempNode;
    }
    else {
       while (ptr->num <= tempNode -> num) {
    
          tempPtr = ptr; 
          ptr = ptr -> next;
       }
   
      tempPtr -> next = tempNode;
      tempNode-> next = ptr;
    } // end of else 

    printf ("Printing after inserting in order \n");
    ptr = head;
    while ( ptr != NULL ) {
        printf ( "%d\n", ptr->num );
        ptr = ptr->next;
    }
    
    
    return 0;
    
}






