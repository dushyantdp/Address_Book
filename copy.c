#include"main.h"

// This function is to copy data from data.csv to temp.csv file
void copy_data(FILE * mptr, FILE * tptr)
{
    int ch;
    while((ch = fgetc(tptr))!=EOF)
    {
        fputc(ch,mptr);
    }
}