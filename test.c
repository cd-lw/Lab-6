#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int per_num;
    char first_name[50];
    char last_name[50];
    char gender;
    char program[50];
    int age;
    char email[100];
} student;

typedef struct node{
    int index;
    student current_stu;
    struct node *next;
    struct node *previous;
    
} node;

int student_index = 0;

node *head = NULL; //head of database points at nothing at first

void main(){

    node* new_node = (node*) malloc (sizeof(node));

    student* new_student = (student*) malloc (sizeof(student));

    new_node->current_stu = *new_student;
    new_node->index = student_index;

    student_index += 1; //Adds 1 to student index counter

    head = new_node; //the newly added student becomes the head of the list

    if (new_student == NULL){
        printf("Error allocating memory");
        exit(0);
    }

    printf("Enter Personnummer: ");
    scanf("%d", &new_student->per_num);

    /* printf("Enter first and last name: ");
    scanf("%s %s", &new_student->first_name, &new_student->last_name);

    printf("Enter gender (M/F): ");
    scanf("%s", &new_student->gender);

    printf("Enter Program: ");
    scanf("%s", &new_student->program);

    printf("Enter age: ");
    scanf("%d", &new_student->age);

    printf("Enter Email: ");
    scanf("%s", &new_student->email); */

    printf("\n\n");

    /* if (head==NULL) {
        head = new_node;
        new_node->previous = NULL;
        new_node->next = NULL; 
    } 
    
    else {
        node *current = head;
        while (current -> next != NULL){
            current = current ->next;
        }
        current ->next = new_node;
        new_node -> previous = current;        
    } */

    node *current_node = head;

    while (current_node->next != NULL){
        printf("%d->", current_node->index);
        current_node = current_node->next;
    }

    main();
}