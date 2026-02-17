#include "main.h"
//To create contact  or Adding contacts to file
void create_contact(Addressbook * adrbook)
{
    printf(YELLOW"---------------Add Details-------------"RESET"\n");
    FILE *mfptr = fopen("data.csv","r");
    FILE *tfptr = fopen("temp.csv","w");
    if(fscanf(mfptr,"%d\n",&adrbook->countcontact) == EOF)
    {
        adrbook->countcontact = 0;
    }
    else
    fscanf(mfptr,"%d\n",&adrbook->countcontact);

    adrbook->countcontact++;
    fprintf(tfptr,"%d\n",adrbook->countcontact);
    for(int i=0 ; i<(adrbook->countcontact-1); i++)
    {
        fscanf(mfptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
        fprintf(tfptr,"%s,%s,%s,%s\n",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
    }
    while(1)
    {
        printf(CYAN"Enter your name: "RESET);
        scanf(" %[^\n]",adrbook->contacts.name);
        // printf("Entered name is : %s\n",adrbook->contacts[adrbook->countcontact].name);
        printf("-------------------------------------\n");
        if(val_name(adrbook->contacts.name))
        {
            // printf("Valid name\n");
             if((adrbook->contacts.name[0] >= 97) && (adrbook->contacts.name[0]<= 122))
               adrbook->contacts.name[0] -= 32;
            break;
        } 
        else
        printf(RED"Enter valid name!"RESET"\n");
    }
    while(1)
    {
        printf(CYAN"Enter your Phone: "RESET);
        scanf(" %[^\n]",adrbook->contacts.phone);
        // printf("Entered phone number is : %s\n",adrbook->contacts[adrbook->countcontact].phone);
        printf("-------------------------------------\n");
        // 
        if(val_phone(adrbook->contacts.phone) && unique_phone(adrbook,adrbook->contacts.phone) )
        {
            // printf("Valid phone\n");
            break;
        } 
        else
        printf(RED"Enter valid phone!"RESET"\n");
    }
    while(1)
    {
        printf(CYAN"Enter your email: "RESET);
        scanf(" %[^\n]",adrbook->contacts.email);
        printf("-------------------------------------\n");
        // 
        if(val_email(adrbook->contacts.email)&& unique_email(adrbook, adrbook->contacts.email) )
        {
            break;
        } 
        else
        printf(RED"Enter valid email!"RESET"\n");
    }
    while(1)
    {
        printf(CYAN"Enter your city: "RESET);
        scanf(" %[^\n]",adrbook->contacts.city);
        printf("-------------------------------------\n");
        if(val_name(adrbook->contacts.city))
        {
            if((adrbook->contacts.city[0] <= 97) && (adrbook->contacts.city[0]>= 122))
            adrbook->contacts.city[0] = adrbook->contacts.city[0] - 32;
            break;
        } 
        else
        printf(RED"Enter valid city!"RESET"\n");
    }
    fprintf(tfptr,"%s,%s,%s,%s\n",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
    fclose(mfptr);
    fclose(tfptr);
    FILE *mptr = fopen("data.csv","w");
    FILE *tptr = fopen("temp.csv","r");
    copy_data(mptr, tptr);
    printf(GREEN);
    printf(HCHECK_MARK" Contact Saved "HCHECK_MARK"\n");
    printf(RESET);
    sleep(1);
    fclose(mptr);
    fclose(tptr);
}

//name validation 
int val_name(char *name)
{
    for(int i = 0 ; name[i] != '\0'; i++ )
    {
        if((name[i] >= 'A' && name[i]<='Z')||(name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))
        {
            continue;
        }
        else
        return 0;
    }
return 1;
}

//phone number validation 
int val_phone(char * phone)
{
    for(int i = 0 ; phone[i] != '\0'; i++)
    {
        if(phone[i]>='0' && phone[i] <= '9')
        continue;
    else
    return 0;
}
int len = strlen(phone);
if(len == 10)
{
    return 1;
}
else
return 0;
}

//Email Vallidation 
int val_email(char *email)
{
    int atcount = 0; 
    for(int i = 0; email[i] !='\0'; i++)
    {
        if(email[i] == '@')
        atcount++;
    }
    if(atcount != 1)
    return 0;
    char ext[5];
    int j=0;

    //for ".com" extension
    for(int i = strlen(email)-4; email[i]!='\0'; i++ )
    {
        ext[j] = email[i];
        j++;
    }
    ext[j] = '\0';
    j=0;
    char ext1[4];
    //for ".in" extension
    for(int i = strlen(email)-3; email[i]!='\0'; i++)
    {
        ext1[j] = email[i];
        j++;
    }
    ext1[j] = '\0';
    if((strcmp(ext,".com")== 0) ||(strcmp(ext1,".in")==0))
    {
        return 1;
    }
    else
    return 0;
}

//For unique phone number entered
int unique_phone(Addressbook * adrbook , char * phone)
{
    int count =0 ;
    char name1[50];
    char phone1[14];
    char email1[50];
    char city1[50];
    FILE * mptr = fopen("data.csv","r");
    fscanf(mptr,"%d\n",&count);
    while(fscanf(mptr," %[^,],%[^,],%[^,],%[^\n]",name1,phone1,email1,city1)!=EOF)
    {
        // printf("%s\n%s\n",phone,phone1);
        // fscanf(mfptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
        if(strcmp(phone1,phone) == 0)
        {
            printf(RED"------------------------------------\n");
            
            printf(CROSS_MARK " This Phone Number already exits! " CROSS_MARK"\n");
            printf("------------------------------------"RESET"\n");
            fclose(mptr);
            return 0;
        }
    }
    fclose(mptr);
    return 1;
}

//for unique email
int unique_email(Addressbook * adrbook , char * email)
{
    char email1[50];
    char name1[50];
    char phone1[14];
    char city1[50];
    int count  = 0 ;
    strcpy(email1,email);
    FILE* mptr = fopen("data.csv","r");
    fscanf(mptr,"%d\n",&count);
    while(fscanf(mptr," %[^,],%[^,],%[^,],%[^\n]",name1,phone1,email1,city1)!=EOF)
    {
        if(strcmp(email1,email) == 0)
        {
            printf(RED"--------------------------------\n");
            printf("| This Email is already exits! |\n");
            printf("--------------------------------"RESET"\n");
            fclose(mptr);
            return 0;
        }
    }
    fclose(mptr);
    return 1;
}