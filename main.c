#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adder.h" //Contains structs as well as function for adding students

int per_num;
char first_name[256];
char last_name[256];
char gender;
char program_buffer[256];
int age;
char email[256];

// Temporary storage^^

node *temp = NULL;

void add_single() {

plus_student:

    printf("Enter Personnummer: ");
    scanf("%d", &per_num);

    printf("Enter first and last name: ");
    scanf("%s %s", &first_name, &last_name);

    printf("Enter gender (M/F): ");
    scanf("%s", &gender);

    printf("Enter Program: ");
    scanf("%s", &program_buffer);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter Email: ");
    scanf("%s", &email);

    head = add_student(per_num, first_name, last_name, gender, program_buffer, age, email);

    char yn;

    printf("Would you like to enter another student? \nEnter y for yes. Enter any other key for no.\n\n");

    scanf(" %c", &yn);

    if (yn == 'y')
    {
        goto plus_student;
    }

    printf("\n");
}

void modify_student(int per_num) {
    temp = head;

    if (temp->student == NULL)
        ;
    {
        printf("No students in database");
        return;
    }

    while (temp != NULL)
    { // Traverse through all the nodes from the head until a matching personal number is found
        if (temp->student->per_num == per_num)
        {
            printf("Enter new first name: ");
            scanf("%s", temp->student->first_name);
            printf("Enter new last name: ");
            scanf("%s", temp->student->last_name);
            printf("Enter new gender: ");
            scanf("%s", temp->student->gender);
            printf("Enter new program: ");
            scanf("%s", temp->student->study_program);
            printf("Enter new age: ");
            scanf("%d", temp->student->age);
            printf("Enter new email: ");
            scanf("%s", temp->student->email);
            getchar();
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!");
    return;
}

void delete_student() {
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

        printf("Student  %d deleted\n" , per_num);

        return;

        }
            previous = current:
            current = current->next:
        }
            printf ("not found %d \n", per_num):
        }
    */
}

void search_student() {
    // Ask user input
    int choice;
    printf("Choose a search method:\n");
    printf("1. Search by Personal Number\n");
    printf("2. Search by Name\n");
    printf("3. Search by Program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Search by Personal Number
        int per_num;
        printf("Enter the personal number: ");
        scanf("%d", &per_num);

        temp = head;
        while (temp != NULL) {
            if (temp->student->per_num == per_num) {
                printf("Student found!\n");
                printf("Personal Number: %d\n", temp->student->per_num);
                printf("First Name: %s\n", temp->student->first_name);
                printf("Last Name: %s\n", temp->student->last_name);
                printf("Gender: %c\n", temp->student->gender);
                printf("Program: %s\n", temp->student->study_program);
                printf("Age: %d\n", temp->student->age);
                printf("Email: %s\n", temp->student->email);
                return; 
            }
            temp = temp->next;
        }
        printf("No student found with that personal number.\n");

    } else if (choice == 2) {
        // Search by Name
        char name[256];
        printf("Enter the name of the student ");
        scanf("%s %s", name, name + strlen(name) + 1);

        temp = head;
        while (temp != NULL) {
            if (strcmp(temp->student->first_name, name) == 0 && strcmp(temp->student->last_name, name + strlen(name) + 1) == 0) {
                printf("Student found!\n");
                printf("Personal Number: %d\n", temp->student->per_num);
                printf("First Name: %s\n", temp->student->first_name);
                printf("Last Name: %s\n", temp->student->last_name);
                printf("Gender: %c\n", temp->student->gender);
                printf("Program: %s\n", temp->student->study_program);
                printf("Age: %d\n", temp->student->age);
                printf("Email: %s\n", temp->student->email);
                return; 
            }
            temp = temp->next;
        }
        printf("No student found with that name.\n");

    } else if (choice == 3) {
        // Search by Program
        printf("Enter the program: ");
        scanf("%s", program_buffer);

        temp = head;
        while (temp != NULL) {
            if (strcmp(temp->student->study_program->prog_name, program_buffer) == 0) {
                printf("Student found!\n");
                printf("Personal Number: %d\n", temp->student->per_num);
                printf("First Name: %s\n", temp->student->first_name);
                printf("Last Name: %s\n", temp->student->last_name);
                printf("Gender: %c\n", temp->student->gender);
                printf("Program: %s\n", temp->student->study_program);
                printf("Age: %d\n", temp->student->age);
                printf("Email: %s\n", temp->student->email);
                return; 
            }
            temp = temp->next;
        }
        printf("No student found in that program.\n");

    } else {
        printf("Invalid choice.\n");
    }
}

void save_file() {
    /*
    The program asks for a file name and saves all information in the database into the file. If the file exits,
    it will be overwritten and if it does not exist it has to be created
    */

    char filename[256];

    printf("\n\nPlease enter the file you would like to save to. If no such file exists a new one will be created.\nAny pre-existing information in the file will be overwritten\n\n");
    scanf("%s", &filename);

    FILE *filptr = fopen(filename, "w");

    temp = head;

    while (temp != NULL)
    {

        fprintf(filptr, "%d ", temp->student->per_num);       // per_num
        fprintf(filptr, "%s ", temp->student->first_name);    // first_name
        fprintf(filptr, "%s ", temp->student->last_name);     // last_name
        fprintf(filptr, "%c ", temp->student->gender);        // gender
        fprintf(filptr, "%s ", temp->student->study_program); // program
        fprintf(filptr, "%d ", temp->student->age);           // age
        fprintf(filptr, "%s\n", temp->student->email);        // email

        temp = temp->next;
    }

    printf("\n\nWrote to file\n\n");

    fclose(filptr);

    return;
}

void load_file() {

    char filename[256];

    printf("\nEnter file name: ");
    scanf(" %s", &filename);

    FILE *filptr = fopen(filename, "r");

    while (feof(filptr) == 0)
    {

        fscanf(filptr, "%d ", &per_num);
        fscanf(filptr, "%s ", &first_name);
        fscanf(filptr, "%s ", &last_name);
        fscanf(filptr, "%c ", &gender);
        fscanf(filptr, "%s ", &program_buffer);
        fscanf(filptr, "%d ", &age);
        fscanf(filptr, "%s\n", &email);

        head = add_student(per_num, first_name, last_name, gender, program_buffer, age, email);
    }

    node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->student->per_num);
        printf("%s ", temp->student->first_name);
        printf("%s ", temp->student->last_name);
        printf("%c ", temp->student->gender);
        printf("%s ", temp->student->study_program);
        printf("%d ", temp->student->age);
        printf("%s-->\n", temp->student->email);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\ndatabase loaded\n");

    fclose(filptr);
}

void add_program()
{
    /*
    The program asks for a file name and saves all information in the database into the file. If the file exits, it will be overwritten
    and if it does not exist it has to be created.
    */
    char prog_n[64];
    char prog_c[10];
    char resp_n[64];
    char resp_e[128];
    // Temp buffer^^

    if (prog_count > 50)
    {
        printf("Reached maximum program limit");
        return;
    }

    printf("Name of program: \n");
    scanf("%s", &prog_n);
    printf("Program code: \n");
    scanf("%s", &prog_c);
    printf("Name of program responsible: \n");
    scanf("%s", &resp_n);
    printf("Responsible email: \n");
    scanf("%s", &resp_e);

    strcpy(array_prog[prog_count].prog_name, prog_n);
    strcpy(array_prog[prog_count].prog_code, prog_c);
    strcpy(array_prog[prog_count].prog_resp, resp_n);
    strcpy(array_prog[prog_count].resp_email, resp_e);
    prog_count++;
}

void modify_program()
{
    /*
    The program ask the program by asking its code and let the user to modify informations about the program
    */

    char name[50];
    char prog_n1[50];
    char prog_c1[10];
    char resp_n1[50];
    char resp_e1[100];

    printf("\n\nType in the name of the program you would like to modify: ");
    scanf("%s", &name);

    for (int i = 0; i < prog_count; i++)
    {
        if (strcmp(array_prog[i].prog_name, name) == 0)
        {   // Loop through all arrays until an element in an array matches the name inputted by the user
            printf("Enter new program name: \n");
            scanf("%s", &prog_n1);
            printf("Enter new program code: \n");
            scanf("%s", &prog_c1);
            printf("Enter new program responsible: \n");
            scanf("%s", &resp_n1);
            printf("Enter program responsible email: \n");
            scanf("%s", &resp_e1);

            strcpy(array_prog[i].prog_name, prog_n1);
            strcpy(array_prog[i].prog_code, prog_c1);
            strcpy(array_prog[i].prog_resp, resp_n1);
            strcpy(array_prog[i].resp_email, resp_e1);

            return;
        }

        else
        {
            printf("Program not found\n");
            modify_program();
        }
    }
}

void exit_function()
{
    /*
    The program sks to save the database. Then it will do the same actions in option 5 (Save) and then exits.
    */

    temp = head;
    node *next_temp;
    char choice1;
    printf("Do you want to save current database? y/n: ");
    scanf("%s", &choice1);
    if (choice1 == 'y')
    {
        // Some code for file saving
        // Some code for file saving
        while (temp != NULL)
        {                           // Traverse through all nodes and free the one by one
            next_temp = temp->next; // Since temp will be freed we must pre define the next node so that we can keep track of the nodes
            free(temp->student);
            temp = next_temp;
        }
        printf("Freed allocated memory, terminating program");
        exit(0);
    }

    else if (choice1 == 'n')
    {
        while (temp != NULL)
        {
            next_temp = temp->next;
            free(temp->student);
            temp = next_temp;
        }
        printf("Freed allocated memory, terminating program");
        exit(0);
    }

    else
    {
        printf("Please enter only either y or n");
        exit_function();
    }
}

void print_function(){
    node* temp = head;
    printf("-------------------------------------------------\n");
    while (temp != NULL){
        printf("Personal Number: %d\n", temp->student->per_num);
        printf("First Name: %s\n", temp->student->first_name);
        printf("Last Name: %s\n", temp->student->last_name);
        printf("Gender: %s\n", temp->student->gender);

        if(temp->student->study_program != NULL){
        printf("Program: %s\n", temp->student->study_program);
        }
        else{
            printf("Program: Not assigned");
        }

        printf("Age: %d\n", temp->student->age);
        printf("Email: %s\n", temp->student->email);
        printf("-------------------------------------------\n");
        temp = temp->next;
    }
}

void print_programs(){
    printf("Amount of programs: %d\n" , prog_count);
    for(int i = 0; i<prog_count; i++){
        printf("-----------------------------------------\n");
        printf("Program Name: %s\n", array_prog[i].prog_name);
        printf("Program code: %s\n", array_prog[i].prog_code);
        printf("Program responsible: %s\n", array_prog[i].prog_resp);
        printf("Responsible email: %s\n", array_prog[i].resp_email);
        printf("-----------------------------------------\n");
    }
}

int main()
{

    int choice = 0;

    printf("Enter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n 10. See functions\n 11. See Programs");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
        add_single();
        // done

        break; // A while loop could have been used here but a goto statement felt more readable and thus more fitting in this case

    case 2:
        printf("Enter Personnummer: \n");
        scanf("%d", &per_num);

        modify_student(per_num);
        // done
        break;

    case 3:
        delete_student();
        // done not merged
        break;

    case 4:
        search_student();
        // almost done
        break;

    case 5:
        save_file();
        // done
        break;

    case 6:
        load_file();
        // done
        break;

    case 7:
        add_program();
        // done
        break;

    case 8:
        modify_program();
        // done
        break;

    case 9:

        exit_function();
        // done
        break;

    case 10:
        print_function();
        break;

     case 11:

        print_programs();
        break;

    default:

        temp = head;

        while (temp != NULL)
        {
            printf("%d ", temp->student->per_num);
            printf("%s ", temp->student->first_name);
            printf("%s ", temp->student->last_name);
            printf("%c ", temp->student->gender);
            printf("%s ", temp->student->study_program);
            printf("%d ", temp->student->age);
            printf("%s-->\n", temp->student->email);
            temp = temp->next; // Move down the list to the last node
        }

        // for debugging

        printf("\n\nPlease enter a number from 1 to 11\n\n");

        break;
    }

    main();
}