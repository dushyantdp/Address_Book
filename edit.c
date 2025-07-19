#include "main.h"


//To Edit contact
void edit_contact(Addressbook * adrbook)
{
   int option = 1, choice = 0;
   int count = 0 ;
   char edit[50];
   FILE * mptr = fopen("data.csv","r");
   if(mptr == NULL)
   {
        printf(RED);
        printf(CROSS_MARK " File Not Opened "CROSS_MARK"\n");
        printf(RESET);
        return;
   }
   fscanf(mptr,"%d\n",&count);
   if(count == 0)
   {
        printf(RED);
        printf(CROSS_MARK" File is Empty "CROSS_MARK"\n");
        printf(RESET);
        return;
   }
   while(option)
   {
       printf(MAGENTA"1. To edit\n2. Return To main menu"RESET"\n");
        printf(CYAN"Enter choice: "RESET);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf(CYAN"Enter your phone number or Email : "RESET);
                    scanf(" %s[^\n]",edit);
                    edit_name(adrbook,edit);
                    break;
            case 2: option = 0;
                    break;
            default :   system("clear");
                        printf(RED);
                        printf(CROSS_MARK" INVALID INPUT "CROSS_MARK"\n");
                        printf(RESET);
                        sleep(1);

        }
   }
}


//To edit Specific detail 
void edit_name(Addressbook * adrbook, char * edit)
{
    int flag = 0;
    FILE * mptr = fopen("data.csv","r");
    FILE * tptr = fopen("temp.csv","w");
    if(mptr == NULL)
    {
        printf(RED"Data file Not opened"RESET"\n");
        return;
    }
    if(tptr == NULL)
    {
        printf(RED"Temp file NOt opened"RESET"\n");
        return;
    }
    int choose = 0;
    printf(MAGENTA"1. To edit name\n");
    printf("2. To edit phone\n");
    printf("3. To edit email\n");
    printf("4. To edit city\n");
    printf("5. Back"RESET"\n");
    printf(CYAN"Enter your choice: "RESET);
    scanf("%d",&choose);
    clear_stdin();
    int count = 0;
    fscanf(mptr,"%d\n",&count);
    fprintf(tptr,"%d\n",count);
    while(fscanf(mptr," %[^,], %[^,], %[^,], %[^\n]", adrbook->contacts.name, adrbook->contacts.phone, adrbook->contacts.email, adrbook->contacts.city)!=EOF)
    {
        if((strcmp(edit,adrbook->contacts.phone) == 0) || (strcmp(edit,adrbook->contacts.email)==0))
        { 
            flag = 1;
            switch(choose)
            {
                case 1: while(1)
                        {
                            printf(CYAN"Enter your name: "RESET);
                            scanf(" %[^\n]",adrbook->contacts.name);
                            printf("-------------------------------------\n");
                            if(val_name(adrbook->contacts.name))
                            {
                                if((adrbook->contacts.name[0] >= 97) && (adrbook->contacts.name[0]<= 122))
                                    adrbook->contacts.name[0] -= 32;
                                break;
                            } 
                            else
                            {
                                printf(RED);
                                printf(CROSS_MARK" Enter valid name! "CROSS_MARK"\n");
                                printf(RESET);
                            }
                        }
                        break;
                case 2: while(1)
                        {
                            printf(CYAN"Enter your Phone: "RESET);
                            scanf(" %[^\n]",adrbook->contacts.phone);
                            printf("-------------------------------------\n"); 
                            if(val_phone(adrbook->contacts.phone) && unique_phone(adrbook,adrbook->contacts.phone) )
                            {
                                break;
                            } 
                            else
                            {
                                printf(RED);
                                printf(CROSS_MARK" Enter valid phone! "CROSS_MARK"\n");
                                printf(RESET);
                            }
                        }
                        break;
                case 3: while(1)
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
                            {
                                printf(RED);
                                printf( CROSS_MARK" Enter valid email! "CROSS_MARK"\n");
                                printf(RESET);
                            }
                    }
                    break;
                    case 4: while(1)
                    {
                        printf(CYAN"Enter your city: "RESET);
                        scanf(" %[^\n]",adrbook->contacts.city);
                        // printf("Entered name is : %s\n",adrbook->contacts[adrbook->countcontact].name);
                        printf("-------------------------------------\n");
                        if(val_name(adrbook->contacts.city))
                        {
                            // printf("Valid name\n");
                            if((adrbook->contacts.city[0] >= 97) && (adrbook->contacts.city[0]<= 122))
                            adrbook->contacts.city[0] -= 32;
                        break;
                    } 
                            else
                            {
                                printf(RED);
                                printf(CROSS_MARK" Enter valid city! " CROSS_MARK"\n");
                                printf(RESET);
                            }
                    }
                    break;
                    case 5 : return;
                    default : system("clear");
                            printf(RED);
                            printf(CROSS_MARK" INVALID INPUT "CROSS_MARK"\n");
                            printf(RESET);
                            sleep(2);
                } 
                
                
            }
            fprintf(tptr,"%s,%s,%s,%s\n",adrbook->contacts.name,adrbook->contacts.phone,adrbook->contacts.email,adrbook->contacts.city);
    }
    if(flag==0)
    {
        printf(RED);
        printf(CROSS_MARK" Contact Not Found "CROSS_MARK"\n");
        printf(RESET);
    }
    else
    {
        printf(GREEN);
        printf(HCHECK_MARK" Contact Edited "HCHECK_MARK"\n");
        printf(RESET);
        printf("-------------------------------------\n");
    }
    fclose(mptr);
    fclose(tptr);
    FILE *mfptr = fopen("data.csv","w");
    FILE *tfptr = fopen("temp.csv","r");
    copy_data(mfptr, tfptr);
    fclose(mfptr);
    fclose(tfptr);
    printf(GREEN);
    printf(HCHECK_MARK" Saved "HCHECK_MARK"\n");  
    printf(RESET);
}