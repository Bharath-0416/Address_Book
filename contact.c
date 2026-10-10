#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//Macros used for Colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

int temp_arr[MAX_CONTACTS];
int array_index_count=0;
// char str2[50];
void listContacts(AddressBook *addressBook)      // int sortCriteria
{
    // Sort contacts based on the chosen criteria
    // List contacts
    // Printing Contacts with name mobile and email
    printf(CYAN" ________________________________________________________________________\n"RESET);
    printf(CYAN"|-------------------------Contact Details--------------------------------|\n"RESET);
    printf(CYAN"|"RESET);
    printf(YELLOW"%-20s %-20s %-30s"RESET,"Contact Name","Mobile No.","E-Mail");
    printf(CYAN"|\n"RESET);
    // for loop -> i to contactcount in address book
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        printf(CYAN"|"RESET);
        printf(GREEN"%-20s %-20s %-30s"RESET,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf(CYAN"|\n"RESET);
    }
   printf(CYAN"|________________________________________________________________________|\n"RESET);
}

void initialize(AddressBook *addressBook) {
    // Before loading contacts from file.c contact count is set to Zero
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
    
}

void saveAndExit(AddressBook *addressBook) {
    
    // Contacts Saved to file
    saveContactsToFile(addressBook); // Save contacts to file
    
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/*logic to create a Contacts */
   
    // char str[20];
    // printf("Enter contact name ");
    // scanf(" %[^\n]",str); 
    char str2[50];
    int n1=isvalid_name(str2,addressBook);  //fun returns 1 if name is with proper validations    

    int n2=0,n3=0;
    if(n1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name,str2); //name is copied to structure only if n1 is 1
        // Mobile is validated only when name is completed
        n2=isvalid_mobile(str2,addressBook);    //fun returns 1 if Phone no. is with proper validations  
    }
    if(n1 && n2)
    {
        // Mail is validated after name and phone
        strcpy(addressBook->contacts[addressBook->contactCount].phone,str2);
        n3=isvalid_mail(str2,addressBook);
    }
    if(n1 && n2 && n3)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,str2);
        addressBook->contactCount++;
    }
    else{
        // if above cases fails returned to the called ones contactcount will not increase
        return;
    }
}

int searchContact(AddressBook *addressBook) 
{
    /*logic for search */
    int search;
    do{
        // int temp_arr[100]={};

        int n,count_index=-1;
        printf("\n1.serch by name\n2.search by mobile\n3.search by mail\n");
        scanf("%d",&n);
        if(n==1)
        {
            // searchbyname
            char str[50];
            printf("Enter the name to search\n");
            scanf(" %[^\n]",str);
          
            // str is string given by user and it is used search with name in the structure list we have
            int x=0;
            for(int i=0;i<(addressBook->contactCount);i++)
            {
                char *res=strstr(addressBook->contacts[i].name,str);//strstr returns the address only if substring is in main string
                //strstr-> returns NULL if sub string is not in main string         strstr(dest_string,src_substring)
                if(res!=NULL)
                {
                    count_index=i;
                    if(x==0)
                    {
                        // Only one time prints and then x becomes 1
                        x=1;
                        printf(CYAN" ___________________________________________________________________________\n"RESET);
                        printf(CYAN"|------------------------------Contact Details------------------------------|\n"RESET);
                        printf(CYAN"|"RESET);
                        printf(YELLOW"%-7s %-20s %-20s %-25s"RESET,"Index","Name","Mobile","E-Mail");
                        printf(CYAN"|\n"RESET);
                        // printf("|---------------------------------------------------------------------------|\n");
                    }
                    
                    temp_arr[array_index_count]=i+1;    //temp_arr stores the index 
                    printf(CYAN"|"RESET);//Index i gives from 0 to count so i+1 now from 1
                    printf(GREEN"%d\t %-20s %-20s %-25s"RESET,i+1,addressBook->contacts[count_index].name,addressBook->contacts[count_index].phone,addressBook->contacts[count_index].email);
                    printf(CYAN"|\n"RESET);
                    array_index_count++;         //array_index__count increases  
                }
            }
            if(x)//base line prints only if above line prints
                printf(CYAN"|___________________________________________________________________________|\n"RESET);
            else{
                printf(RED"No Details Found"RESET);
            }
            
            search=0;
        }
        else if(n==2)
        {
            // search by mobile
            char str[20];
            printf("Enter the phone Number to search\n");
            scanf(" %s",str);
           // str is string given by user and it is used search with phn no. in the structure list we have
            int x=0;
            for(int i=0;i<(addressBook->contactCount);i++)
            {
                char *res=strstr(addressBook->contacts[i].phone,str);
                if(res!=NULL)
                {
                    count_index=i;
                    if(x==0)
                    {
                        x=1;
                        printf(CYAN" ___________________________________________________________________________\n"RESET);
                        printf(CYAN"|------------------------------Contact Details------------------------------|\n"RESET);
                        printf(CYAN"|"RESET);
                        printf(YELLOW"%-7s %-20s %-20s %-25s"RESET,"Index","Name","Mobile","E-Mail");
                        printf(CYAN"|\n"RESET);
                        // printf("|---------------------------------------------------------------------------|\n");
                    }                    
                    temp_arr[array_index_count]=i+1;//temp_arr stores the index 
                    printf(CYAN"|"RESET);
                    printf(GREEN"%d\t %-20s %-20s %-25s"RESET,i+1,addressBook->contacts[count_index].name,addressBook->contacts[count_index].phone,addressBook->contacts[count_index].email);
                    printf(CYAN"|\n"RESET);  
                    array_index_count++;   
                }
            }
            if(x)
                printf(CYAN"|___________________________________________________________________________|\n"RESET);
            else{
                printf(RED"No Details Found"RESET);
            }
            search=0;
        }
        else if(n==3)
        {
            // search by mail
            char str[50];
            printf("Enter the Mail to search\n");
            scanf(" %[^\n]",str);
            int x=0;

            for(int i=0;i<(addressBook->contactCount);i++)
            {
                // Checks substring with main string
                char *res=strstr(addressBook->contacts[i].email,str);
                if(res!=NULL)
                {
                    count_index=i;
                    if(x==0)
                    {
                        x=1;
                        printf(CYAN" ___________________________________________________________________________\n"RESET);
                        printf(CYAN"|------------------------------Contact Details------------------------------|\n"RESET);
                        printf(CYAN"|"RESET);
                        printf(YELLOW"%-7s %-20s %-20s %-25s"RESET,"Index","Name","Mobile","E-Mail");
                        printf(CYAN"|\n"RESET);
                        // printf("|---------------------------------------------------------------------------|\n");
                    }
                    temp_arr[array_index_count]=i+1;////temp_arr stores the index 
                    printf(CYAN"|"RESET);
                    printf(GREEN"%d\t %-20s %-20s %-25s"RESET,i+1,addressBook->contacts[count_index].name,addressBook->contacts[count_index].phone,addressBook->contacts[count_index].email);
                    printf(CYAN"|\n"RESET); 
                    array_index_count++;              
                }
            }
            if(x)
                printf(CYAN"|___________________________________________________________________________|\n"RESET);
            else{
                printf(RED"No Details Found"RESET);
            }
            

            search=0;
        }
        else if(n!=1 && n!=2 && n!=3)
        {
            printf(YELLOW"Invalid option\n"RESET);
        }


        if(count_index==-1)
        {
            char l;
            printf(CYAN"\nDo you want to search again?\n"RESET);
            printf(YELLOW"Press y to search.\t or any key to Cancel\n "RESET);
            scanf(" %c",&l);
            if(l!='Y' && l!='y')
            {
                search=0;
                return 1;
            }
            else{
                search=1;
            }
        }       

    }while(search);
    return 0;
}

void editContact(AddressBook *addressBook)
{
	/*logic for Editcontact */
    
    // temp_arr[100]={0};
    int f=0;
    f=searchContact(addressBook);//search returns a val so that it goes to main if name/phn/mail doesnt match in search
    if(f==1)
    {
        return;
    }
    int ind,flag=0;
    printf("Enter the indx you want to edit:");
    scanf("%d",&ind);

    for(int i=0;i<array_index_count;i++)
    {
        // this arr is for checking multiple indexes are available the list of o/p of search 
        
        if(ind==temp_arr[i])
        {
            flag=1;
            break;            
        }
    }
    if(flag==0)
    {
        // if index doesnt match in 
        printf("Invalid index\n");
        return;
    }
    else
    {
        do{
            int opt;
            printf("1.Edit by name:\n2.Edit by Mobile\n3.Edit by email\n");
            scanf("%d",&opt);
            char str2[50];
            if(opt==1)
            {
                
                if(isvalid_name(str2,addressBook)==1)
                {
                    // printf("Contact count-->%d\n",addressBook->contactCount);
                    // printf("index variable%d\n",ind);
                    strcpy(addressBook->contacts[ind-1].name,str2);
                }
            }
            else if(opt==2)
            {
                if(isvalid_mobile(str2,addressBook)==1)
                {
                    // printf("Contact count-->%d\n",addressBook->contactCount);
                    // printf("index variable%d\n",ind);
                    strcpy(addressBook->contacts[ind-1].phone,str2);
                }

            }
            else if(opt == 3)
            {
                if(isvalid_mail(str2,addressBook)==1)
                {
                    // printf("Contact count-->%d\n",addressBook->contactCount);
                    // printf("index variable%d\n",ind);

                    strcpy(addressBook->contacts[ind-1].email,str2);
                }

            }
            else
            {
                printf("Invalid option\n");

            }
        }while(0);
    }
    
}

void deleteContact(AddressBook *addressBook)
{
	
    /*logic for deletecontact */
    int f=0;
    f=searchContact(addressBook);
    if(f==1)    //search returns a val so that it goes to main if name/phn/mail doesnt match in search
    {
        return;
    }
    int index,flag=1;
    printf("Enter index you want to delete\n");
    scanf("%d",&index);
    for(int i=0;i<array_index_count;i++)
    { // this arr is for checking multiple indexes are available the list of o/p of search 
        if(temp_arr[i]==index)
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        printf("Invalid Index\n");
    }
    else
    {
        char n;
        
        printf("Are you sure to delete permanently\nTo continue Press any key.\nTo go back press ");
        printf(GREEN"N\n"RESET);

        scanf(" %c",&n);
        if(n=='n' || n=='N')
        {   //Exits if n or N is pressed
            return;
        }
        printf("Deleting Contact:......\n");
        for(int i=0;i<(addressBook->contactCount);i++)
        {
            if((i+1)==index)
            {
                for(int j=i;j<(addressBook->contactCount);j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];

                }
                break;
            }
        }
        addressBook->contactCount--;
        printf(RED"Contact Deleted\n"RESET);
    }
}
int  isvalid_name(char * str2,AddressBook * addressBook)
{
    (void)addressBook;      //Here we are not using addressbook structure
    int j=3;
    while(j)                 //For 3 attempts
    {
        char str[50];
        printf("Enter Name:\n");
        scanf(" %[^\n]",str);
        int flag1=0;

        int i=0;
        int count=0;
        int flag=0;
        while(str[i]!='\0')
        {
            
            if(isalpha(str[i]) || str[i]=='.' || str[i] == ' ')
            {
                count++;
            }
            else
            {
                flag=1; 
            }
            i++;
        }
        
        if(count<4)
        {
            printf("Name must be 4 characters\n");        //Error msg
            flag1++;
        }
        else if(flag==1)
        {
            printf("Name must be alpha characters\n");         //Error msg
            flag1++;
        }
        else{

            printf("Entered Name is %s\n",str);     //Prints the name entered after passing validations

            strcpy(str2,str); 
            return 1;
        }
        if(flag1!=0)
        {   
            printf(RED"Attempts left:%d\n"RESET,j-1);
            j--;

        }
        if(j==0){
            return 0;
        }
        
    }
    return 0;
}
int isvalid_mobile(char * str2,AddressBook * addressBook)
{
    int j=3;
    while(1)
    {
        char str_num[20];
        printf("Enter Mobile Number\n");
        scanf(" %[^\n]",str_num);
        int i=0,length=0,count_num=0;
        while(str_num[i]!='\0')
        {
           
            if(str_num[i]>='0' && str_num[i]<='9')
            {
                count_num++;
            }
             i++;
            length++;

        }
        // printf("Count_num: %d,length:%d",count_num,length);
        int flag1=1;
        if(str_num[0]>'9' || str_num[0]<'6')                        //Errorr Message
        {
            printf("Mobile Number Should start from 6 to 9\n");
        }
        else if(length!=10)                                         //Errorr Message
        {
            printf("Mobile no. should contain 10 characters\n");
        }
        else if(count_num!=length)
        {
            printf("Mobile Number should contain only numbers\n");
        }
        else{
            int save=1;
            for(int k=0;k<(addressBook->contactCount);k++)
            {
                if((strcmp(addressBook->contacts[k].phone,str_num))==0)
                {
                    save=0;
                    printf("Mobile No. already Exists.Try again\n");
                    break;
                }
            }
            if(save==1)
            {
                flag1=0;
                printf("Mobile Number :\t%s\n",str_num);
                strcpy(str2,str_num); 
                return 1;   
            }

        }
        if(flag1)
        {

            printf(RED"Attempts left:%d\n"RESET,j-1);
            j--;
        }
        if(j==0){
            return 0;
        }
    }
    
}


int isvalid_mail(char * str2,AddressBook *addressBook)
{
    int j=3;
    while(1)
    {
        char str_mail[50];
        printf("Enter mail");
        scanf(" %[^\n]",str_mail);
        
        
        int i=0;
        int count=0;
        int flag=0;
        int length=0,at_index=-1,dot_index=-1;

        while(str_mail[i]!='\0')
        {
            if(isalpha(str_mail[i]) || isdigit(str_mail[i]) || str_mail[i]=='.' || str_mail [i]=='@')
            {
                count++;
                if(str_mail[i]=='@')
                {
                    at_index=i;
                }
                else if(str_mail[i]=='.')
                {
                    dot_index=i;

                }
            }
            

            i++;
            length++;
            
        }
        if(at_index==-1 || dot_index==-1)
        {
            printf("Atleast one time '@' and '.' should be there\n");
        }
        else if(count!=length)
        {
            printf("Special Characters are not allowed\n");
        }
        else if(dot_index<at_index)
        {
            printf("@ is mandatory before .");
        }
        else if((dot_index-at_index) <= 1)
        {
            printf("At least one character should be between @ and .\n");
        }
        else
        {
             int save=1;
            for(int k=0;k<(addressBook->contactCount);k++)
            {
                if((strcmp(addressBook->contacts[k].email,str_mail))==0)
                {
                    save=0;
                    printf(RED"Mobile No. already Exists\n"RESET);
                    break;
                }
            }
           if(save)
           {
            flag=1;
            printf(BLUE"Mail: %s"RESET,str_mail);
            strcpy(str2,str_mail);    
            return 1;   

           }           
            
        }
        if(flag==0)
        {
            printf(RED"Atempts left: %d\n"RESET,j-1);
        }
    
        if(j==0)
        {
            return 0;

        }
        j--;

    }
    
}
// temp array Edit and delete Operation completed
void cleararray()
{
    array_index_count=0;
}

