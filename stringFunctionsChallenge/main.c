/*
Author: Billy Gene Ridgeway
Date: June 18, 2022
Purpose:
    1. Display a string in reverse order using scanf and strlen.
    2. Write a program that sorts 3 user inputted strings usinb bubble sort, srtcmp and strcpy.
*/

#include <stdio.h>
#include <stdlib.h>

void stringReverse(void);
void bubbleSort(void);


int main()
{

    void stringReverse(void)
    {
        char myString[100];
        printf("\nPlease enter a string of characters without spaces.\n");
        scanf("%s", myString);
        char revString[strlen(myString)-1];     // Initialize a string to store the characters in reverse.

        int i=0;
        int j=strlen(myString)-1;


        for(i=(strlen(myString)-1); i>=0; i--)    // For loop to print the characters in reverse order.
        {
            revString[j] = myString[i];
            printf("%c", revString[j]);

        }
        printf("\n");

    }

    void bubbleSort(void)
    {
        char bubbles[25][50];       // Initialize a 2D array to hold up to 50, 25 character strings.
        char temp[25];              // Initialize a tempory array for swapping strings.
        int s, i, j;

        printf("\nEnter the number of strings you would like to sort.\nEnter all characters in either uppercase, or lowercase only.\nYou can enter up to fifty strings each of up to 25 characters without spaces.\n");
        scanf("%d", &s);

        printf("\nEnter %d strings.\n\n", s);

        for(i=0; i<s; i++)     // For loop to input the user's input into the array.
        {
            scanf("%s", bubbles[i]);
        }

        for(i=1; i<=s; i++)                                               // Loop each string.
            for(j=0; j<=s-1; j++)
            if(strcmp(bubbles[j], bubbles[j+1])>0)                        // Compare each string to see if the first string is greater than the second.
        {                                                                 // Sizeof(xx) -1, so the null character is not included. '\0'
            strncpy(temp, bubbles[j], sizeof(temp) -1);                   // Store the first string in the temp string.
            strncpy(bubbles[j], bubbles[j+1], sizeof(bubbles[j]) -1);     // Store the second string in the first string.
            strncpy(bubbles[j+1], temp, sizeof(bubbles[j]+1) -1);         // Move the first string from the temp string into the second string.
        }

        printf("\nThe strings you entered after being sorted with bubble sort:\n");

        for(i=0; i<=s; i++)                 // Prints out each string in order after the bubble sort.
            printf("%s\n", bubbles[i]);

    }


    stringReverse();
    bubbleSort();
    return 0;
}
