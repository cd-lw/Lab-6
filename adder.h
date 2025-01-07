#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int per_num;
    char first_name[256];
    char last_name[256];
    char gender; 
    char program[256];
    int age;
    char email[256];
} student;

typedef struct node{
    student *student;
    struct node *next;
    struct node *prev;
    
} node;

node *head = NULL; //head of the list, points to nothing at in

node *add_student(int per_num, char *first_name, char *last_name, char gender, char *program, int age, char *email){ 

    node* new_node = (node*) malloc (sizeof(node));

    student* new_student  = (student*) malloc (sizeof(student));

    //                              NEED TO ADD "FREE"

    if (new_student == NULL){
        printf("Error allocating memory");
        exit(0);
    }

    new_node->student = new_student;
   
    new_node->next = NULL; //So that the last pointer in the list is always NULL

    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    }

    else {
        node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;

        new_node->prev = temp;
    }

    new_student->per_num = per_num;

    strcpy(new_student->first_name,  first_name);

    strcpy(new_student->last_name, last_name);

    new_student->gender = gender;

    strcpy(new_student->program, program);

    new_student->age = age;

    strcpy(new_student->email, email);
 
    /* while(temp != NULL && temp->next != NULL) {
        temp = temp->next; // Move down the list to the last node
    }

    while (temp != NULL){
        printf("%d<--", temp->student.first_name);
        temp = temp->prev; // Start moving up towards the head
    }

    printf("\n"); */

    return head; //returns the head pointer of the list
}