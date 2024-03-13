#include <stdio.h>
#include <stdlib.h>

struct data {
    int num; 				/* data stored in the node  */
    struct data * next; 	/* pointer to the next node */
};

typedef struct data datatype;
void printAll (datatype * temp);

int main () {
    
    int i;
    
   datatype * head;
   datatype * ptr;
   
    /* create one node - the first one */
   
   // step 1: create the node and assign values to it
   ptr = malloc (sizeof (datatype));
   ptr->num = 10;
   ptr->next = NULL;
   
   // step 2: set the head to be this node - since
   // it is the first one in the list
   head = ptr;
   
   //create second node at the beginning of the list
   
   // step 1: create the node and assign values to it
   ptr = malloc (sizeof (datatype));
   ptr->num = 20;
   
   // step 2: make the newly created node as the
   // head of the list
   ptr->next = head;
   head = ptr;
   
   // create 3 more nodes added to the beginning
   // of the list
   for (i = 0; i < 3; i++) {
      
      // step 1: create the node and assign values to it
      ptr = malloc (sizeof (datatype));
      ptr->num = i + 30;
      
      // step 2: make the newly created node as the
      // head of the list
      ptr->next = head;
      head = ptr;
      
   }
   
   // add the next node to the end of the list
   // step 1: create the node and assign values to it
   // step 2: traverse the list to reach the last element
   // step 3: finally, link the last element to the newly created node
   
   // step 1
   datatype * newNode;
   newNode = malloc (sizeof (datatype));
   newNode->num = 200;
   newNode->next = NULL;
   
   //step 2
   ptr = head;       //caution - dont meddle
                     // with head of the LL
   
   while (ptr->next != NULL) {
      ptr = ptr->next;
   }
   
   // step 3
   ptr->next = newNode;
   
   // call printAll to print all the elements of the LL
   printAll (head);
            
    return 0;
}

void printAll (datatype * temp) {
   
   while (temp != NULL) {
      
      printf ("%d \n", temp->num);
      temp = temp->next;
   }
}
