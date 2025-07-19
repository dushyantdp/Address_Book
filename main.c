#include "main.h"

void main()
{
    Addressbook addressbook;
    printf(YELLOW"-------Addressbook Project--------"RESET"\n");
    int choice = 1, option = 0;
    char find[50];
    while(choice)
    {
        printf("-------------------------------------\n");
        printf(MAGENTA"1. Create Contact\n");
        printf("2. Edit Details\n");
        printf("3. Display Contacts\n");
        printf("4. Search Contacts\n");
        printf("5. Delete Specific Contact\n");
        printf("6. Delete All Contacts\n");
        printf("7. Exit Program"RESET"\n");
        printf("-------------------------------------\n");
        printf(CYAN"Enter choice: "RESET);
        scanf("%d",&option);
        clear_stdin();
        printf("-------------------------------------\n");
        switch(option)
        {
                case 1: create_contact(&addressbook);
                    break;
                case 2: edit_contact(&addressbook);
                    break;
                case 3: list_contacts(&addressbook);
                    break;
                case 4: printf(CYAN"Enter name or phone or email : "RESET);
                    scanf(" %[^\n]", find);
                    search(&addressbook, find);
                    break;
                case 5: delete_contact(&addressbook);
                    break;
                case 6: delete_all_contact(&addressbook);
                    break;
                case 7: choice = 0;
                        printf(GREEN);
                        printf(BYE" See You Soon "BYE"\n");
                        printf(RESET);
                        break;
                default:   system("clear");
                            printf(RED);
                            printf(CROSS_MARK" INVALID INPUT "CROSS_MARK"\n");
                            printf(RESET);
                            sleep(1);
        }  
    }
}

void clear_stdin()
{
    int c;
    while((c = getchar()) != '\n' && (c != EOF));
}