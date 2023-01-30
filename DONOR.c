#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct DONORInformation
{
    struct DONORInformation *next;
    char Name [50];
    char BloodGroup [10];
    char MobileNumber[11];
} DONOR;

void InsertInformation (DONOR **head);
void DisplayInformation (DONOR *head);
void SearchInformation (DONOR *head);

int main ()
{
    char YN [3], C [5];
    DONOR *head = NULL;
    int n, i;
    printf ("How many DONOR's information do you have initially?\n");
    scanf ("%d", &n);
    for (i=0; i<n; i++)
    {
        InsertInformation (&head);
        DisplayInformation (head);
    }
    while (1)
    {
        printf ("\n[ADD / SEARCH / EXIT]\n");
        fflush (stdin);
        gets (C);
        if (strcmp (C, "ADD") == 0)
            {
                InsertInformation (&head);
                DisplayInformation (head);
            }
        else if (strcmp (C, "SEARCH") == 0)
            SearchInformation (head);
        else if (strcmp (C, "EXIT") == 0)
            break;
        else
            printf ("\nWRONG KEYWORD!\n");
    }
}

void InsertInformation (DONOR **head)

{
    DONOR *temp = NULL;
    temp = (DONOR*) malloc (sizeof(DONOR));
    printf ("\nDONOR's Name: ");
    fflush (stdin);
    gets (temp -> Name);
    printf ("DONOR's Blood Group: ");
    fflush (stdin);
    gets (temp -> BloodGroup);
    printf ("DONOR's Mobile Number: ");
    fflush (stdin);
    gets (temp -> MobileNumber);
    temp -> next = *head;
    *head = temp;
}

void DisplayInformation (DONOR *head)
{
    printf ("\nUPDATED:\n");
    while (head != NULL)
    {
        puts (head -> Name);
        puts (head -> BloodGroup);
        puts (head -> MobileNumber);
        printf ("\n");
        head = head -> next;
    }
}

void SearchInformation (DONOR *head)
{
    int F = 0;
    char BG [10];
    printf ("\nSearch By Blood Group: ");
    gets (BG);
    while (head != NULL)
    {
        if (strcmp(BG, head -> BloodGroup) == 0)
        {
            printf ("\n");
            puts (head -> Name);
            puts (head -> MobileNumber);
            F++;
        }
        head = head -> next;
    }
    if (F == 0)
            printf ("\nNOT FOUND!\n");
}

