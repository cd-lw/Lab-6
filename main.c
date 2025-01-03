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
    student *student;
    struct node *next;
    struct node *prev;
    
} node;

node *head = NULL; //head of the list, points to nothing at init

void add_student(int per_num, char *first_name, char *last_name, char *gender, char *program, int age, char *email){ 

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

    *new_student->first_name = first_name;

    *new_student->last_name = last_name;

    new_student->gender = gender;

    *new_student->program = program;

    new_student->age = age;

    *new_student->email = email;

    printf("\n\n");

    /* node *temp = head; 

    while(temp != NULL) {
        printf("%d-->", temp->student->per_num);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\n"); */
 
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


void modify_student(){
/*

char temp_num[50];
char temp_fname[50];
char temp_lname[50];
char temp_gender[50];
char new_program[50];
int new_age = 0;
char new_lname[50];
printf("Enter Student Personal Number: ");
scanf("%s", &temp_num);

for (int i = 0; i <student_index; i++){
    if (db[i]->per_num == temp_num){
        printf("Enter new personal number: ");
        scanf("%s", &new_num);
        db[i]->per_num = new_num;

        printf("Enter First Name");
        scanf("%s", &temp_fname);
        db[i]->name = new_fname;

        printf("Enter Last Name");
        scanf("%s" , &temp_lname);
        db[i]->name = new_fname;

        printf("Enter gender");
        scanf("%s" , temp_gender);
        db[i]->name = new_fname;

        printf("Enter program");
        scanf("%s" , temp_program);
        db[i]->name = new_fname;

        printf("Enter age");
        scanf("%d" , temp_age);
        db[i]->name = new_fname;

        printf("Enter email");
        scanf("%s" , temp_email);
        db[i]->name = new_fname;
        
        break;
    }
    else {
        printf("No student found!");
    }
}

*/
}


void delete_student(){
/*
    int per_num
    printf("Enter Personnumber: ")
        scanf(%d, &per_num);
    node_s *current=head;
    node_s *previous =NULL;

    while (current !=NULL) {
        if (current -> currentd-> pernum==per_num) {
            if(previous ==NULL)
            previous->next = current->next;
            }

        else{
            previous->next = current->next;
            if (current -> next !=NULL) {
                current ->next ->previous = previous;
        }
    }

    printf("person %d deleted \n" , per_num);

    return;

    }
        previous = current:
        current = current->next:
    }
        printf ("not found %d \n", per_num):
    }
*/    

}

void search_student(){
/*
int choice2 = 0;
printf(" 1. Personal number:\n 2. Name\n 3. Study Program\n 4. Statistics");
scanf("%d" , choice2);

switch(choice2); {
    case 1:
    break;

    case 2:
    break;

    case 3:
    break;

    case 4:
    break;

}
*/

}

void save_file(){
/*
The program asks for a file name and saves all information in the database into the file. If the file exits,
it will be overwritten and if it does not exist it has to be created
*/

    char *filename;

    printf("Please enter the file you would like to save to. If no such file exists a new one will be created.\nAny pre-existing information in the file will be overwritten");
    scanf("");

    FILE *filptr = fopen(filename, "w");

    node *temp = head;

    while (temp != NULL) {

        fprintf(filptr, "%d,", temp->student->per_num);      //per_num
        fprintf(filptr, "%s,", temp->student->first_name);   //first_name
        fprintf(filptr, "%s,", temp->student->last_name);    //last_name
        fprintf(filptr, "%s,", temp->student->gender);       //gender
        fprintf(filptr, "%s,", temp->student->program);      //program
        fprintf(filptr, "%d,", temp->student->age);          //age
        fprintf(filptr, "%s,", temp->student->email);        //email
        
        fprintf(filptr, "\n");
        
        temp = temp->next;
    }

    printf("\n\nWrote to file\n\n");

    fclose(filptr);
    
    return;
}

void load_file(){
/*
The program asks for a file name. If the file exists its contents will be loaded into the database. Note that the current information
in the database will be overwritten by the information from the file. Therefore the program asks for a confirmation from the user.
*/

    head = NULL; //Makes head  NULL since any previous information in the database will be overwritten/discarded

   /*  scanf("%d", &new_student->per_num);

    scanf("%s %s", &new_student->first_name, &new_student->last_name); 

    scanf("%s", &new_student->gender);

    scanf("%s", &new_student->program);

    scanf("%d", &new_student->age);

    scanf("%s", &new_student->email);  */

    printf("\n\n");

    /* node *temp = head; 

    while(temp != NULL) {
        printf("%d-->", temp->student->per_num);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\n"); */
 
    /* while(temp != NULL && temp->next != NULL) {
        temp = temp->next; // Move down the list to the last node
    }

    while (temp != NULL){
        printf("%d<--", temp->student.first_name);
        temp = temp->prev; // Start moving up towards the head
    }

    printf("\n"); */

}

void add_program(){
/*
The program asks for a file name and saves all information in the database into the file. If the file exits, it will be overwritten
and if it does not exist it has to be created.
*/

}

void modify_program(){
/*
The program ask the program by asking its code and let the user to modify informations about the program
*/

}

void exit_function(){
    /*
    The program sks to save the database. Then it will do the same actions in option 5 (Save) and then exits.
    */

    exit(0);

}

int main(){

int per_num;
char first_name[50];
char last_name[50];
char gender[3];
char program[50];
int age;
char email[100];
    
node * head = NULL;

int choice = 0;

printf("Enter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n");
scanf("%d", &choice);

switch (choice){

    case 1:

        plus_student:

        printf("Enter Personnummer: ");
        scanf("%d", &per_num);

        printf("Enter first and last name: ");
        scanf("%s %s", &first_name, &last_name); 

        printf("Enter gender (M/F): ");
        scanf("%s", &gender);

        printf("Enter Program: ");
        scanf("%s", &program);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter Email: ");
        scanf("%s", &email);

        add_student(per_num, first_name, last_name, gender, program, age, email);

        char yn;

        printf("Would you like to enter another student? \nEnter y for yes. Enter any other key for no.");

        scanf(" %c", &yn);

        printf("\r\n\n");

        if (yn == 'y') {
            goto plus_student;
        }

        node *temp = head; 

        while(temp != NULL) {
            printf("%d-->", temp->student->per_num);
            temp = temp->next; // Move down the list to the last node
        }

        printf("\n"); 

    break; //A while loop could have been used here but a goto statement felt more readable and thus more fitting in this case

    case 2:
        modify_student();

    break;

    case 3:
        delete_student();

    break;

    case 4:
        search_student();

    break;

    case 5:
        save_file();

    break;

    case 6:
        load_file();

    break;

    case 7:
        add_program();

    break;

    case 8:
        modify_program();

    break;

    case 9:
        exit_function();
    
    break;

    main();

    default:

}

//char *study_prg = &student.gender;




}