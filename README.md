# Address_Book
A console-based C program that lets users add contact records—name, phone, email, city—stored persistently in a CSV file (data.csv). The project reads the CSV on startup to display contacts and appends new entries, using C structs, file I/O, and string parsing for simple contact management. 
Core Functionality:-
Add Contact – Prompt user to enter name, phone, email, and city, then append the new contact to data.csv.
Display All Contacts – Read and parse the CSV file, then list all stored entries in an organized format.
Search Contact – Find and display contacts by any field (name, phone, or email). 
Edit Contact – Locate a specific contact by name, phone, or email and update any of its details.
Delete Specific Contact – Remove a selected contact, then rewrite the CSV without that record.
Delete All Contacts – Clear the entire address book by truncating or deleting the CSV file.
CSV File Persistence – Automatically load data from and save changes to the CSV, ensuring data survives between runs. 
Exit Program – Safely terminate, ensuring any buffered changes are flushed to the file.

Steps to Execute:
1.  Download 'a.out' file from the repo for linux<br>
    dp@DP:/mnt/d/Address_Book$ ./a.out