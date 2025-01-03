#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
int index;
int data;
struct node *next;
struct node *prev;
} node;

int i = 0;

node *head = NULL; //Entryway at the top of the list, points to most recently added node
node *old_node = NULL; //"Mediary" next pointer

void main(){

    node* new_node = (node*) malloc (sizeof(node));

    new_node->next = NULL;

    head = new_node; //The head points to the new node
    
    head->next = old_node; //the next node is the previously created node

    old_node = new_node; //the newly added node is turned into the old node    

    printf("Enter data: ");
    scanf("%d", &new_node->data);
    printf("\n\n");

    node *temp_head = head;

    while (temp_head != NULL) {
        printf("%d-->", temp_head->data);
        temp_head = temp_head->next; //advance the position of the head down the list until it reaches NULL
        //temp_head = temp_head->prev;
    }

    printf("\n\n");
 
    main();
}