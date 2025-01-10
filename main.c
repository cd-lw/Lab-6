#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adder.h" //Contains structs as well as function for adding students

int per_num;
char first_name[64];
char last_name[64];
char gender;
char program_buffer[128];
int age;
char email[256];

char prog_n[64];
char prog_c[10];
char resp_n[64];
char resp_e[128];

char filename[256];

// Temporary IO buffers ^^

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

    if (head == NULL) {
        printf("\n\nFailed to add student\n\n");
    }

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

    int modchoice;

    if (temp->student == NULL){
        printf("No students in database\n\n");
        return;
    }

    while (temp != NULL)
    { // Traverse through all the nodes from the head until a matching personal number is found
        if (temp->student->per_num == per_num)
        {
            printf("What would you like to modify?\n\n1. First name 2. Last name 3. Gender 4. Program 5. Age 6. Email\n\n");
            scanf(" %d", &modchoice);

            switch(modchoice) {
                
                case 1:
                    printf("Enter new first name: ");
                    scanf("%s", temp->student->first_name);
                    break;

                case 2:
                    printf("Enter new last name: ");
                    scanf("%s", temp->student->last_name);
                    break;

                case 3:
                    printf("Enter new gender: ");
                    scanf("%s", temp->student->gender);
                    break;

                case 4:
                    printf("Enter new program: ");
                    scanf("%s", temp->student->study_program);
                    break;
                
                case 5:
                    printf("Enter new age: ");
                    scanf("%d", temp->student->age);
                    break;

                case 6:
                    printf("Enter new email: ");
                    scanf("%s", temp->student->email);
                    break;
            }
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!");
    return;
}

void delete_student() {
    if (head == NULL) {
        printf("The list is empty. No students to delete.\n");
        return;
    }
    int per_num;
    printf("Enter the personal number of the student to delete: ");
    scanf("%d", &per_num);  //to find student personal number 

    node *temp = head;


    while (temp != NULL) {
        if (temp->student->per_num == per_num) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next; 
            } else {
                head = temp->next;  //update head if being deleted 
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev; 
            }
            printf("Student with personal number %d has been deleted.\n", per_num);
            return;
        }
        temp = temp->next; 
    }
    printf("No student found with personal number %d.\n", per_num);
}

void search_student()
{

    // Ask user input
    int choice;
    printf("Choose a search method:\n");
    printf("1. Search by Personal Number\n");
    printf("2. Search by Name\n");
    printf("3. Search by Program\n");
    printf("4. See statistics"); //See total number of students, how many of each gender and their average age
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            // Search by Personal Number
            int per_num;
            printf("Enter the personal number: ");
            scanf("%d", &per_num);

            temp = head;
            while (temp != NULL)
            {
                if (temp->student->per_num == per_num)
                {
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
            break;

        case 2:
            // Search by Name
            char name[256];
            printf("Enter the name of the student ");
            scanf("%s %s", name, name + strlen(name) + 1);

            temp = head;
            while (temp != NULL)
            {
                if (strcmp(temp->student->first_name, name) == 0 && strcmp(temp->student->last_name, name + strlen(name) + 1) == 0)
                {
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
            break;
    
        case 3:
            // Search by Program
            printf("Enter the program: ");
            scanf("%s", program_buffer);

            temp = head;
            while (temp != NULL)
            {
                if (strcmp(temp->student->study_program->prog_name, program_buffer) == 0)
                {
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
            break;

        case 4:
            int total_num = 0; // Total Students
            int total_m = 0; // Total Male Students
            int total_f = 0; // Total Female Students
            int comb_age = 0; // Combined age

            temp = head;

            while (temp != NULL){
                total_num++;
                if (temp->student->gender == 'M'){
                    total_m++;
                }

                if (temp->student->gender == 'F'){
                    total_f++;
                }

                comb_age = comb_age + temp->student->age;
                temp = temp->next;
            }

            printf("Total Number of students: %d\n", total_num);
            printf("Total Number of male students: %d\n", total_m); 
            printf("Total Number of female students: %d\n", total_f); 
            printf("Average age of all students: %d\n", comb_age/total_num); 
            printf("----------------------------------------------------------------\n");

            for(int i = 0; i<prog_count; i++){
                total_num = 0;
                total_m = 0;
                total_f = 0;
                comb_age = 0;
                temp = head; 
    
                while (temp != NULL){
                if (strcmp(temp->student->study_program->prog_name, array_prog[i].prog_name) == 0){
                    if(temp->student->gender == 'M')
                    {
                    total_m++;
                    }

                    if(temp->student->gender == 'F')
                    {
                    total_f++;
                    }
                    total_num++;
                }
                temp = temp->next; 
            }

            printf("----------------------------------------------------------------\n");
            printf("Students in  %s: %d\n",array_prog[i].prog_name , total_num);
            printf("Male Students in  %s: %d\n",array_prog[i].prog_name , total_m);
            printf("Female Students in  %s: %d\n",array_prog[i].prog_name , total_f);
            printf("----------------------------------------------------------------\n");

            }
            break;
    
        default:
            printf("Invalid choice.\n");
            break;
    }
}


void add_program(char *prog_name, char *prog_code, char *prog_resp, char *resp_email)
{
    /*
    The program asks for a file name and saves all information in the database into the file. If the file exits, it will be overwritten
    and if it does not exist it has to be created.
    */

    if (prog_count == 50)
    {
        printf("Reached maximum program limit");
        return;
    }

    strcpy(array_prog[prog_count].prog_name, prog_name);
    strcpy(array_prog[prog_count].prog_code, prog_code);
    strcpy(array_prog[prog_count].prog_resp, prog_resp);
    strcpy(array_prog[prog_count].resp_email, resp_email);
    prog_count++;
    return;
}

void save_file()
{
    /*
    The program asks for a file name and saves all information in the database into the file. If the file exits,
    it will be overwritten and if it does not exist it has to be created
    */

    printf("\n\nPlease enter the file you would like to save to. If no such file exists a new one will be created.\nAny pre-existing information in the file will be overwritten\n\n");
    scanf("%s", &filename);

    FILE *filptr = fopen(filename, "w");

    while (prog_count != 0)
    {
        fprintf(filptr, "%s ", array_prog[prog_count].prog_name);
        fprintf(filptr, "%s ", array_prog[prog_count].prog_code);
        fprintf(filptr, "%s ", array_prog[prog_count].prog_resp);
        fprintf(filptr, "%s\n", array_prog[prog_count].resp_email);
        prog_count--;
    }

    fprintf(filptr, "|\n");

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

    printf("\nEnter file name: ");
    scanf(" %s", &filename);

    FILE *filptr = fopen(filename, "r");

    while (fgetc(filptr) != '|') {

        fseek(filptr, -1, SEEK_CUR); //Move filepointer back one step to counteract fgetc moving it forward
    
        fscanf(filptr, "%s ", &prog_n);
        fscanf(filptr, "%s ", &prog_c);
        fscanf(filptr, "%s ", &resp_n);
        fscanf(filptr, "%s\n", &resp_e);

        add_program(prog_n, prog_c, resp_n, resp_e);
    }

    //fseek(filptr, 1, SEEK_CUR);

    while (feof(filptr) == 0)
    {

        fscanf(filptr, "%d ", &per_num);
        fscanf(filptr, "%s ", &first_name);
        fscanf(filptr, "%s ", &last_name);
        fscanf(filptr, "%c ", &gender);
        fscanf(filptr, "%s ", &program_buffer);
        fscanf(filptr, "%d ", &age);
        fscanf(filptr, "%s\n", &email);

        add_student(per_num, first_name, last_name, gender, program_buffer, age, email);
    }

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

    printf("\ndatabase loaded\n");

    fclose(filptr);
}

void modify_program() {
    /*
    The program ask the program by asking its code and let the user to modify informations about the program
    */

    char name[50];

    printf("\n\nType in the name of the program you would like to modify: ");
    scanf("%s", &name);

    for (int i = 0; i < prog_count; i++)
    {
        if (strcmp(array_prog[i].prog_name, name) == 0)
        { // Loop through all arrays until an element in an array matches the name inputted by the user
            printf("Enter new program name: \n");
            scanf("%s", &prog_n);
            printf("Enter new program code: \n");
            scanf("%s", &prog_c);
            printf("Enter new program responsible: \n");
            scanf("%s", &resp_n);
            printf("Enter program responsible email: \n");
            scanf("%s", &resp_e);

            strcpy(array_prog[i].prog_name, prog_n);
            strcpy(array_prog[i].prog_code, prog_c);
            strcpy(array_prog[i].prog_resp, resp_n);
            strcpy(array_prog[i].resp_email, resp_e);

            return;
        }

        else
        {
            printf("Program not found\n");
            modify_program();
        }
    }
}

void exit_function() {
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
        save_file();

        while (temp != NULL)
        {                           // Traverse through all nodes and free them one by one
            next_temp = temp->next; // Since temp will be freed we must predefine the next node so that we can keep track of them
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

void print_function() {
    temp = head;

    if (temp == NULL) {printf("\nNo students in memory\n");}

    printf("-------------------------------------------------\n");
    while (temp != NULL)
    {
        printf("Personal Number: %d\n", temp->student->per_num);
        printf("First Name: %s\n", temp->student->first_name);
        printf("Last Name: %s\n", temp->student->last_name);
        printf("Gender: %c\n", temp->student->gender);

        if (temp->student->study_program != NULL)
        {
            printf("Program: %s\n", temp->student->study_program);
        }
        else
        {
            printf("Program: Not assigned");
        }

        printf("Age: %d\n", temp->student->age);
        printf("Email: %s\n", temp->student->email);
        printf("-------------------------------------------\n");
        temp = temp->next;
    }
}

void print_programs() {
    printf("\n\nAmount of programs: %d\n", prog_count);
    printf("-----------------------------------------\n\n");

    for (int i = 0; i < prog_count; i++)
    {
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

    printf("\nEnter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n 10. See list of students\n 11. See Programs\n\n");
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
        // done
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

        printf("Name of program: \n");
        scanf("%s", &prog_n);
        printf("Program code: \n");
        scanf("%s", &prog_c);
        printf("Name of program responsible: \n");
        scanf("%s", &resp_n);
        printf("Responsible email: \n");
        scanf("%s", &resp_e);

        add_program(prog_n, prog_c, resp_n, resp_e);
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