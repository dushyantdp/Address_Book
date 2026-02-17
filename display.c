#include"main.h"

// To display contacts
void list_contacts(Addressbook * adrbook)
{
   FILE * fptr = fopen("data.csv","r");
    if(fptr == NULL)
    {
      printf(RED);
      printf("File Not opened\n");
      printf(RESET);
      return;
    }
    fscanf(fptr,"%d\n",&adrbook->countcontact);
    if(adrbook->countcontact == 0)
    {
      printf(RED);
      printf("NO Contacts Found\n");
      printf(RESET);
      return;
    }
    Contact disp[adrbook->countcontact];
    int i = 0;
    while(fscanf(fptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city) && (i != adrbook->countcontact))
    {
      strcpy(disp[i].name, adrbook->contacts.name);
      strcpy(disp[i].phone, adrbook->contacts.phone);
      strcpy(disp[i].email, adrbook->contacts.email);
      strcpy(disp[i].city,adrbook->contacts.city);
      // printf(" %s, %s, %s, %s\n",disp[i].name,disp[i].phone,disp[i].email,disp[i].city);
      i++;
    }
    i--;
    fclose(fptr);
    int choice;
    printf("-------------------------------------\n");
    printf(MAGENTA"Select sort by:\n");
    printf("1. Sort By Name\n2. As Entered\n3. Return to Main Menu"RESET"\n");
    // printf("-------------------------------------\n");
    int option=1;
    
    while(option)
    {
      // printf("-------------------------------------\n");
      printf(CYAN"Enter Choice: "RESET);
      scanf("%d",&choice);
      clear_stdin();
      printf("-------------------------------------\n");
      switch(choice)
      {
        case 1: sort_by_name(disp, adrbook->countcontact); 
                break; 
        case 2: display(adrbook);
                break;
        case 3: option = 0;
                break;
        default:  system("clear");
                  printf(RED);
                  printf(CROSS_MARK" INVALID INPUT "CROSS_MARK"\n");
                  printf(RESET);
                  sleep(1);
      }
    }
}

// To display as per stored in file
void display(Addressbook * adrbook)
{
  FILE * mptr = fopen("data.csv","r");
  fscanf(mptr,"%d\n",&adrbook->countcontact);
  printf(YELLOW"------------All Contacts---------------"RESET"\n");
  while(fscanf(mptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city)!=-1)
  {
    printf(BLUE"Name  :"RESET" %s\n",adrbook->contacts.name);
    printf(BLUE"Phone :"RESET" %s\n",adrbook->contacts.phone);
    printf(BLUE"Email :"RESET" %s\n",adrbook->contacts.email);
    printf(BLUE"City  :"RESET" %s\n",adrbook->contacts.city);
    printf("---------------------------------------\n");
  }
  fclose(mptr);
}

// To Display contacts in Alphabetical Order
void sort_by_name(Contact * disp, int size)
{
  Contact swap;
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size-1; j++)
    {
      if(disp[j].name[0]>=disp[j+1].name[0])
      {
        swap=disp[j];
        disp[j]=disp[j+1];
        disp[j+1]=swap;
      }
    }
  }
  for(int k = 0; k<size; k++)
  {
    printf(BLUE"Name  :"RESET " %s\n",disp[k].name);
    printf(BLUE"Phone :"RESET " %s\n",disp[k].phone);
    printf(BLUE"Email :"RESET " %s\n",disp[k].email);
    printf(BLUE"City  :"RESET " %s\n",disp[k].city);
    printf("---------------------------------------\n"); 
  }
}




