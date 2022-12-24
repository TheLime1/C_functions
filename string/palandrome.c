#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definition for "is_palindrome"
// Takes a string as an argument and returns 1 if the string is a palindrome, and 0 if it is not
int is_palindrome(char str[])
{
    int i, length;
    int palindrome = 1; // assume the string is a palindrome

    length = strlen(str); // get the length of the string

    // check if the string is a palindrome by comparing the characters at the
    // beginning and end of the string and working our way towards the middle
    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            palindrome = 0; // the string is not a palindrome
            break;
        }
    }

    return palindrome;
}

// Function declaration for "is_palindrome"
int is_palindrome(char str[]);

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str); // read the string from the user

    // Call the "is_palindrome" function to check if the string is a palindrome
    int result = is_palindrome(str);

    // Print the result of the check
    if (result == 1)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
