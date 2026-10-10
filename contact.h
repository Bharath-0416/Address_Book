#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
 

//created  for validation of name,phone and email 
int isvalid_name(char * str2,AddressBook *addressBook);
int isvalid_mobile(char * str2,AddressBook *addressBook);
int isvalid_mail(char * str2,AddressBook *addressBook);
void cleararray();

#endif
