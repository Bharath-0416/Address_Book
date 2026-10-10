/*
Name: G Bharath

Batch:26015B

Project Title:Address Book

Documentation:

A structure the name,mail,phone with size .This structure is nested with the other structure and it contains contact count.
In the main() firstly we intiallize the contacts from the file.The list is printed with create,search,edit,delete,list,exit.
It doesnt take other i/p throws the error as a Error.
CREATE CONTACT:In this, we create the name,phn,mail.
    The validations are done in individual functions.It provides the three attempts.If the attempts are completed returns to the main.
    Otherwise Stored in structure and increases the contactCount.
SEARCH Contact:the search contact takes the input string from the user and searches it with in the structure.If matches any of the val in the structure it prints with the indexes.Otherwise shows the Error as No Details Fund.
EDIT Contact: Edit operation is performed only when the search gives any indexes.The search takes the input string from the user and searches it with in the structure.If matches any of the val in the structure it prints with the indexes.
                if we give index no in edit it edits in that index only It performs Edit by name/phn/mail.here we take string from usr ,what the user gives the string is again validated (by name/mobile/mail).And stored in structure.
DELETE Contact:Delete also similar to Edit.After taking the indexes from search. It ask the usr which index you want to delete . Here we are asking confirmation to delete by taking i/p char from ur.
LISTING Conatcts: We will print the contacts which are available in the Structure
EXIT: Asks the Confirmation from the usr with char.While Exiting,The contacts are Saved to the file.The contacts are saved seperated by comma.so that at the time of loading contacts it is easy.
    

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
