#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function definition for "compare_strings"
// Takes two strings as arguments and compares them, returning 1 if they are the same and 0 if they are different
int compare_strings(char str1[], char str2[])
{
    int result;

    // Compare the strings using the "strcmp" function from the "string.h" library
    result = strcmp(str1, str2);

    // If the result is 0, the strings are the same, so return 1
    // Otherwise, the strings are different, so return 0
    if (result == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function declaration for "compare_strings"
int compare_strings(char str1[], char str2[]);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    // Read the two strings from the user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Call the "compare_strings" function to compare the strings
    int result = compare_strings(str1, str2);

    // Print the result of the comparison
    if (result == 1)
    {
        printf("The strings are the same.\n");
    }
    else
    {
        printf("The strings are different.\n");
    }

    return 0;
}
