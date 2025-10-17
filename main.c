#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARACTERS 50
#define INIT_TOT_STUDENTS 10
#define RESIZE_LIMIT 6

// external variables
char **email_addresses;

// function prototypes
void read_emails(void);
void display_emails(int);
void free_memory(int, int);
void shrink_email_addresses(void);

int main(void)
{
    // reading 10 email addresses
    read_emails();
    printf("\nStored Emails: \n");
    display_emails(INIT_TOT_STUDENTS);

    // shrinking email list to just 6 emails..
    shrink_email_addresses();
    printf("\n Renewed list of emails after resizing:\n");
    display_emails(RESIZE_LIMIT);
    free_memory(0, RESIZE_LIMIT);

    return 0;
}

/* function definitions. */

/**
 * read_emails: function that read emails from user
 *
 * Return: void always.
 **/
void read_emails(void)
{
    email_addresses = malloc(INIT_TOT_STUDENTS * sizeof(char *));

    if (email_addresses == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < INIT_TOT_STUDENTS; i++)
    {
        email_addresses[i] = malloc(MAX_CHARACTERS * sizeof(char));
        if (email_addresses[i] == NULL)
        {
            printf("Inner allocation failed");
            exit(1);
        }
    }

    for (int i = 0; i < INIT_TOT_STUDENTS; i++)
    {
        printf("Enter email for student %d: ", i + 1);
        scanf("%s", email_addresses[i]);
    }
}

/**
 * display_emails - function that displays emails to stdout.
 * @tot_students: the number of student whose emails should be displayed
 *
 * Return - void always.
 **/
void display_emails(int tot_students)
{
    for (int i = 0; i < tot_students; i++)
        printf("%d. %s.\n", i + 1, email_addresses[i]);
}

/**
 * free_memory: function that deallocates memory after usage.
 * @start: marks the beginning memory block
 * @end: marks the end of the memory block to be freed
 *
 * Returns - void always
 **/
void free_memory(int start, int end)
{
    for (int i = start; i < end; i++)
        free(email_addresses[i]);

    free(email_addresses);
}

/**
 * free_memory: function that resizes emails list
 *
 * Returns - void always
 **/
void shrink_email_addresses(void)
{
    for (int i = RESIZE_LIMIT; i < INIT_TOT_STUDENTS; i++)
        free(email_addresses[i]); // freeing the memory that is holding last 4 emails.

    char **temp = realloc(email_addresses, (sizeof(char *) * RESIZE_LIMIT));
    if (temp != NULL)
        email_addresses = temp;
    else
    {
        printf("Re-allocation failed.\n");
        free_memory(0, RESIZE_LIMIT);
        exit(1); // terminate the program
    }
}