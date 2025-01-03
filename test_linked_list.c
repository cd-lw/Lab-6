#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
int index;
int data;
struct node *next;
<<<<<<< HEAD
struct node *prev;
} node;

int i = 0;

node *head = NULL; //Entryway at the top of the list, points to most recently added node
node *old_node = NULL; //"Mediary" next pointer
=======
struct node *previous;
} node;

int outer_index = 0;

node *head; //Entryway at the top of the list, points to most recently added node
node *p; // "Mediary" pointer for new_node and head
>>>>>>> 590d4ac148912c6c15b085b3de6e37840ec61ebb

void main(){

    node* new_node = (node*) malloc (sizeof(node));

<<<<<<< HEAD
    new_node->next = NULL;

    head = new_node; //The head points to the new node
    
    head->next = old_node; //the next node is the previously created node

    old_node = new_node; //the newly added node is turned into the old node    
=======
    new_node->index = outer_index; //creates index for every node

    head = new_node; //The head points to the new node
    new_node->next = NULL; //new node gets a NULL pointer

    /* if (new_node->index == 0) {
        new_node->next = NULL;
        p = new_node;
    } */
    
    /* else {
        head->next = p;
        p = new_node;
    } */

    head->next = p; //The node that the head points to, is made the same as the node that p points to (the previous node)
    p = new_node; //p now points to the new node

    outer_index += 1;
>>>>>>> 590d4ac148912c6c15b085b3de6e37840ec61ebb

    printf("Enter data: ");
    scanf("%d", &new_node->data);
    printf("\n\n");

<<<<<<< HEAD
    node *temp_head = head;

    while (temp_head != NULL) {
        printf("%d-->", temp_head->data);
        temp_head = temp_head->next; //advance the position of the head down the list until it reaches NULL
        //temp_head = temp_head->prev;
    }

    printf("\n\n");
 
    main();
=======
    while(head->next != NULL) {
        printf("%d-->", head->data);
        head = head->next; //advance the position of the head down the list until it reaches NULL
    }
    
    printf("\n\n");

    main(); //Call "add node" function
>>>>>>> 590d4ac148912c6c15b085b3de6e37840ec61ebb
}