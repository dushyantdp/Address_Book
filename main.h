#ifndef MAIN_H
#define MAIN_H
#define MAX_CONTACTS 100

// neccessary header files
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<unistd.h>
#include<stdlib.h>

//symbols used
#define CHECK_MARK "\xE2\x9C\x93"
#define HCHECK_MARK "\xE2\x9C\x94"
#define CROSS_MARK "\u2718"
#define SMILE "\U0001F600"
#define WELCOME "\U0001F64F"
#define BYE "\U0001F44B"

//Colour used
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"


typedef struct{
    char name[50];
    char phone[20];
    char email[50];
    char city[50];
}Contact;

typedef struct{
    Contact contacts;
    int countcontact;
}Addressbook;

void create_contact(Addressbook *);
void list_contacts(Addressbook * );
void sort_by_name(Contact *, int);
void sort_by_email(Addressbook *);
void sort_by_phone(Addressbook * );
void search(Addressbook * , char *);
void By_name(Addressbook *); 
void By_phone(Addressbook * );
void By_email(Addressbook * );
void delete_contact(Addressbook *);
void delete_all_contact(Addressbook *);
void delete_by_phone(Addressbook * );
void delete_by_email(Addressbook * );
void edit_contact(Addressbook *);
void edit_name(Addressbook *, char *);
void clear_stdin(void);
void display(Addressbook *);

//copy file data
void copy_data(FILE *, FILE *);

// create file function prototypes
int val_name(char *);
int val_phone(char *);
int val_email(char *);
int unique_phone(Addressbook *, char *);
int unique_email(Addressbook *, char *);

#endif