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

/* typedef struct {
    Node *head;
} StudentDatabase;

StudentDatabase *initialize_database;

StudentDatabase *db= (StudentDatabase*) malloc (sizeof(StudentDatabase));
if (db == NULL)  {
    printf("db init fail\n"):
    return NULL
}

db->head = NULL; */

int student_index = 0;

node *head = NULL; //head of database points at nothing at first

void add_student(){ 

    student_index += 1; //Adds 1 to student index counter

    node* new_node = (node*) malloc (sizeof(node));

    student* tempstudent = (student*) malloc (sizeof(student));

    new_node->current_stu = *tempstudent;
    new_node->index = student_index;

    head = new_node; //the newly added student becomes the head of the list

    if (tempstudent == NULL){
        printf("Error allocating memory");
        exit(0);
    }

    printf("Enter Personnummer: ");
    scanf("%d", &tempstudent->per_num);

    printf("Enter first and last name: ");
    scanf("%s %s", &tempstudent->first_name, &tempstudent->last_name);

    printf("Enter gender (M/F): ");
    scanf("%s", &tempstudent->gender);

    printf("Enter Program: ");
    scanf("%s", &tempstudent->program);

    printf("Enter age: ");
    scanf("%d", &tempstudent->age);

    printf("Enter Email: ");
    scanf("%s", &tempstudent->email);

    printf("\n\n");

   /*  if (head==NULL) {
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
    }
    
    current -> next = new_node;
    new_node -> previous = current;
    new_node -> next = NULL */;


    /* 
    printf("%d ", tempstudent->per_num);
    printf("%s ", tempstudent->first_name);
    printf("%s ", tempstudent->last_name);
    printf("%c ", tempstudent->gender);
    printf("%s ", tempstudent->program);
    printf("%d ", tempstudent->age);
    printf("%s ", tempstudent->email);
    */

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

}

void load_file(){
/*
The program asks for a file name. If the file exists its contents will be loaded into the database. Note that the current information
in the database will be overwritten by the information from the file. Therefore the program asks for a confirmation from the user.
*/

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

}
int main(){
    
    
node * head = NULL;
head = (node*) malloc(sizeof(node));

//Database/linked list initialization
    

int choice = 0;

printf("Enter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n");
scanf("%d", &choice);

switch (choice){
    case 1:
        add_student();

    break;

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