#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prog_count = 0;

typedef struct program{
    char prog_name[64];
    char prog_code[10];
    char prog_resp[64];
    char resp_email[128];    
} program;

program array_prog[50]; // Create a static array of 50 program structs

typedef struct student{
    int per_num;
    char first_name[256];
    char last_name[256];
    char gender; 
    program* study_program;
    int age;
    char email[256];
} student;

typedef struct node{
    student *student;
    struct node *next;
    struct node *prev;
    
} node;

node *head = NULL; //head of the list, points to nothing at in

node *temp = NULL;

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

    new_student->study_program = NULL; // Assigned to NULL to avoid undefined behavior if no programs are added


    if (head == NULL) {
        head = new_node;
    }

    else {
        temp = head;

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

    new_student->age = age;

    //strcpy(new_student->study_program->prog_name, program); //segfault

    strcpy(new_student->email, email);
    
    for(int i = 0; i<prog_count; i++){
        if(strcmp(array_prog[i].prog_name, program) == 0){ // Program inputted by user must match any of the programs in the array
            new_student->study_program = &array_prog[i];
            return head; //returns the head pointer of the list
        }
    }

    printf("Program not found, use option 11 to see list of programs\n");
    return NULL; 
}