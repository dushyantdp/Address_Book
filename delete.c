#include "main.h"

// To delete specific contact 
void delete_contact(Addressbook * adrbook)
{
  FILE * mptr = fopen("data.csv","r");
  FILE * tptr = fopen("temp.csv","w");
  if(mptr == NULL)
  {
    printf(RED);
    printf(CROSS_MARK" MAIN file Not opened "CROSS_MARK"\n");
    printf(RESET);
    return;
  }  
  if(tptr == NULL)
  {
    printf(RED);
    printf(CROSS_MARK" Temp file Not opened "CROSS_MARK"\n");
    printf(RESET);
    return;
  }
  char del[50];
  printf(CYAN"Enter phone or email: "RESET);
  scanf(" %[^\n]",del);
  int flag = 0;
  fscanf(mptr,"%d\n",&adrbook->countcontact);
  adrbook->countcontact --;
  fprintf(tptr,"%d\n",adrbook->countcontact);
  while(fscanf(mptr," %[^,],%[^,],%[^,],%[^\n]",adrbook->contacts.name, adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city)!=EOF)
  {
    if((strcmp(del,adrbook->contacts.phone)==0)||(strcmp(del,adrbook->contacts.email)==0))
    {
      flag = 1;
      continue;
    }
    else
    {
      fprintf(tptr,"%s,%s,%s,%s\n",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
    }
  }
  if(flag == 0)
  {
    printf(RED);
    printf(CROSS_MARK" Contact Not Found! " CROSS_MARK"\n");
    printf(RESET);
    return;
  }
  fclose(mptr);
  fclose(tptr);
  char ch;
  printf(CYAN" !! To confirm delete (y/Y) : "RESET);
  scanf(" %c",&ch);
  clear_stdin();
  if((ch == 'y') || (ch =='Y'))
  {
    FILE * mfptr = fopen("data.csv","w");
    FILE * tfptr = fopen("temp.csv","r");
    copy_data(mfptr, tfptr);
    fclose(mfptr);
    fclose(tfptr);
    printf(GREEN);
    printf(HCHECK_MARK" Deleted......\n");
    printf(RESET);
  }
  else
  {
    return;
  }

}


// To Delete ALL contacts in the file or empty file
void delete_all_contact(Addressbook * adrbook)
{
  char ch;
  printf(CYAN" !! To Confirm Delete ALL Data (y/Y) : "RESET);
  scanf(" %c",&ch);
  clear_stdin();
  if((ch == 'y') || (ch =='Y'))
  {
    FILE * fptr = fopen("data.csv","w");
    if(fptr == NULL)
    {
      printf(RED);
      printf("file not opened\n");
      printf(RESET);
      return;
    }
    fprintf(fptr,"%d\n",0);
    fclose(fptr);
    printf(GREEN);
    printf(HCHECK_MARK" Deleted "HCHECK_MARK"\n");
    printf(RESET);
  }
  else
  {
    return;
  }

}
