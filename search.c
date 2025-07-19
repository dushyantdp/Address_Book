#include"main.h"

// To Search the specific contact
void search(Addressbook * adrbook, char * find)
{
    int flag = 0;
    FILE* mptr = fopen("data.csv","r");
    if(mptr == NULL)
    {
        printf("File NOt opened\n");
        return;
    }
    fscanf(mptr,"%d\n",&adrbook->countcontact);
    while(fscanf(mptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name, adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city)!=EOF)
    {
        if((strcmp(find,adrbook->contacts.name)==0)||(strcmp(find,adrbook->contacts.phone)==0)||(strcmp(find,adrbook->contacts.email)==0))
        {
            flag = 1;
            printf(GREEN);
            printf(HCHECK_MARK" Contact Found "HCHECK_MARK"\n");
            printf(RESET);
            printf(BLUE"Name  :"RESET" %s\n",adrbook->contacts.name);
            printf(BLUE"Phone :"RESET" %s\n",adrbook->contacts.phone);
            printf(BLUE"Email :"RESET" %s\n",adrbook->contacts.email);
            printf(BLUE"City  :"RESET" %s\n",adrbook->contacts.city);
            return;
        }
    }
    if(flag==0)
    {
        printf(RED);
        printf(CROSS_MARK" Contact Not Found "CROSS_MARK"\n");
        printf(RESET);
    }

}