/*
Name: G Bharath

Batch:26015B

Project Title:Address Book

Documentation:

The Address Book project uses nested structures to store contact details, including name, phone number, and email, with input validation.
It provides Create, Search, Edit, Delete, and List operations through a menu interface.
Contacts are loaded from and saved to a CSV file to maintain data across program executions.

*/

#include <stdio.h>
#include "contact.h"
// #include "contact.c"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initializing the address book         
    do {
        printf("\n\nAddress Book Menu:\n");
        printf("\n1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        
        switch (choice) {
            case 1:
                createContact(&addressBook);        //performs operation of contact creation
                break;
            case 2:
                searchContact(&addressBook);        //Performs the operation of search with user input and stores the indexes in global arr
                break;
            case 3:
                editContact(&addressBook);      //Edit operation is performed after searching operation completed
                cleararray();   //clears the temp_arr which is used store the indexes after search operation
                break;
            case 4:
                deleteContact(&addressBook);        //Delete operation is performed after searching operation completed
                cleararray();   //clears the temp_arr which is used store the indexes after search operation
                break;
            case 5:
                // printf("Select sort criteria:\n");
                // printf("1. Sort by name\n");
                // printf("2. Sort by phone\n");
                // printf("3. Sort by email\n");
                // printf("Enter your choice: ");
                // int sortChoice;
                // scanf("%d", &sortChoice);
                listContacts(&addressBook);         //listContacts(&addressBook, sortChoice);   
                break;
            case 6:
                char t;
                printf("Press y to exit");  //For confirmation
                scanf("%c",&t);    
                if(t=='Y' || t=='y')     //Exits only when user presses y or Y
                {
                    printf("Saving and Exiting...\n");
                    saveContactsToFile(&addressBook);
                }
                else{
                    choice=1;
                }

                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}

