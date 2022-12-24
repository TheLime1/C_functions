#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, length;
    int palindrome = 1; // assume the string is a palindrome

    printf("Enter a string: ");
    scanf("%s", str); // read the string from the user

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

    if (palindrome)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
