#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {

    FILE *fp;
    fp=fopen("file.csv","w+");      //If the file contains any contacts also are overwritten    (at load the same contacts are taken to the structure)
    int limit=addressBook->contactCount;
    for(int i=0;i<limit;i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp;
    fp=fopen("file.csv","r");       //The contacts are read from file
    
    if(fp==NULL)    
    {
        printf("File Doesnt exist \n");
        return;
    }
    int i=0;
    while(fscanf(fp," %[^,],%[^,],%[^\n]",addressBook->contacts[i].name,
                                        addressBook->contacts[i].phone,
                                        addressBook->contacts[i].email)==3)
    {
        i++;
    }
    // assigns the contact Count with i
    addressBook->contactCount=i;
    fclose(fp);
    
    
}
