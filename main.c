#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adder.h" //Contains structs as well as function for adding students

int per_num;
char first_name[256];
char last_name[256];
char gender;
char program[256];
int age;
char email[256];

//Temporary storage^^

node *temp = NULL; 

void add_single(){

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

        head = add_student(per_num, first_name, last_name, gender, program, age, email);

        char yn;

        printf("Would you like to enter another student? \nEnter y for yes. Enter any other key for no.\n\n");

        scanf(" %c", &yn);

        if (yn == 'y') {
            goto plus_student;
        }

        printf("\n"); 
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

    char filename[256];

    printf("\n\nPlease enter the file you would like to save to. If no such file exists a new one will be created.\nAny pre-existing information in the file will be overwritten\n\n");
    scanf("%s", &filename);

    FILE *filptr = fopen(filename, "w");

    temp = head;

    while (temp != NULL) {

        fprintf(filptr, "%d ", temp->student->per_num);      //per_num
        fprintf(filptr, "%s ", temp->student->first_name);   //first_name
        fprintf(filptr, "%s ", temp->student->last_name);    //last_name
        fprintf(filptr, "%c ", temp->student->gender);       //gender
        fprintf(filptr, "%s ", temp->student->program);      //program
        fprintf(filptr, "%d ", temp->student->age);          //age
        fprintf(filptr, "%s\n", temp->student->email);        //email
        
        temp = temp->next;
    }

    printf("\n\nWrote to file\n\n");

    fclose(filptr);
    
    return;
}

void load_file(){

    char filename[256];

    printf("\nEnter file name: ");
    scanf(" %s", &filename);

    FILE *filptr = fopen(filename, "r");

    while (feof(filptr) == 0) {

        fscanf(filptr, "%d ", &per_num);
        fscanf(filptr, "%s ", &first_name);
        fscanf(filptr, "%s ", &last_name);
        fscanf(filptr, "%c ", &gender);
        fscanf(filptr, "%s ", &program);
        fscanf(filptr, "%d ", &age);
        fscanf(filptr, "%s\n", &email);

        head = add_student(per_num, first_name, last_name, gender, program, age, email);

    }

    node *temp = head; 

    while(temp != NULL) {
        printf("%d ", temp->student->per_num);
        printf("%s ", temp->student->first_name);
        printf("%s ", temp->student->last_name);
        printf("%c ", temp->student->gender);
        printf("%s ", temp->student->program);
        printf("%d ", temp->student->age);
        printf("%s-->\n", temp->student->email);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\ndatabase loaded\n");

    fclose(filptr);

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

int choice = 0;

printf("Enter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n");
scanf("%d", &choice);

switch (choice){

    case 1:
        add_single();
        //done

    break; //A while loop could have been used here but a goto statement felt more readable and thus more fitting in this case

    case 2:
        modify_student();
        //done not merged
        break;

    case 3:
        delete_student();
        //done not merged
        break;

    case 4:
        search_student();
        //almost done
        break;

    case 5:
        save_file();
        //done
        break;

    case 6:
        load_file();
        //done
        break;

    case 7:
        add_program();
        //done not merged
        break;

    case 8:
        modify_program();
        //done not merged
        break;

    case 9:
        save_file();

        exit_function();
        //done
        break;

    default:

        temp = head; 

        while(temp != NULL) {
            printf("%d ", temp->student->per_num);
            printf("%s ", temp->student->first_name);
            printf("%s ", temp->student->last_name);
            printf("%c ", temp->student->gender);
            printf("%s ", temp->student->program);
            printf("%d ", temp->student->age);
            printf("%s-->\n", temp->student->email);
            temp = temp->next; // Move down the list to the last node
        }

        //for debugging

        printf("\n\nPlease enter a number from 1 to 9\n\n");

        break;
    }

    main();
}