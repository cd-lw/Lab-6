#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
//int index;
int data;
struct node *next;
struct node *prev;
} node;

//int outer_index = 0;

node *head; //Entryway at the top of the list, points to most recently added node

void add_node(){
    
    node* new_node = (node*) malloc (sizeof(node));

    new_node->next = NULL; 
    
    new_node->prev = NULL;

    if (head == NULL) { 
        head = new_node;
    } 

    //if there is no "head" node make the added node the head node
    
    else {
        node *temp = head;

        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new_node;

        new_node->prev = temp;
    }

    //else store the head node in a temp var while the next node of the temporary pointer is not null
    //make the temporary pointer into the next pointer
    //when temp->next is null, add the new node at the position of temp->next
    //make the previous node of new_node the temporary node

    printf("Enter data: ");
    scanf("%d", &new_node->data);
    printf("\n\n");
}

void print_forwards(){

    node *temp = head; 

    while(temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\n");
}

void print_backwards(){

    node *temp = head;

    while(temp != NULL && temp->next != NULL) {
        temp = temp->next; // Move down the list to the last node
    }

    while (temp != NULL){
        printf("%d<--", temp->data);
        temp = temp->prev; // Start moving up towards the head
    }
    printf("\n");
}

void main(){

int choice;

while(1){
    printf(" 1. Add Node\n 2. Print forward\n 3. Print backwards\n");
    scanf("%d" , &choice);

    switch(choice){
        case 1:
        add_node();
        break;
        case 2:
        print_forwards();
        break;
        case 3:
        print_backwards();
        break;
        default:
        main();
        break;
    }
}

}