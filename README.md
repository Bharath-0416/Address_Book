# Address Book

## About the Project
This is a menu-driven Address Book application developed using C programming. It helps users manage contact information, including names, phone numbers, and email addresses. The project uses structures to store contact details and file handling to save contacts for future use.

## Features
- **Create Contact:** Add a new contact with name, phone number, and email.
- **Search Contact:** Find contacts using a name, phone number, or email.
- **Edit Contact:** Update the details of an existing contact.
- **Delete Contact:** Remove a contact after confirmation.
- **List Contacts:** Display all saved contacts.
- **Save and Load Contacts:** Store contacts in a CSV file and load them when the program starts.

## Technologies Used
- C Programming
- Structures
- Functions
- File Handling
- CSV File Format

## How to Compile
Make sure GCC is installed on your system. Open a terminal in the project folder and run:

```bash
gcc -Wall -Wextra -std=c11 main.c contact.c file.c -o address_book
```

## How to Run

On Linux or WSL, run:

```bash
./address_book
```

## What I Learned
Through this project, I practised using structures, functions, input validation, searching, and file handling in C. I also learned how to organize a program into multiple source and header files.

## Author
**G. Bharath Goud**
