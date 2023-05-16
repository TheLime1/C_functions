#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *s)
{
    int i, j;
    char temp;

    // find the length of the string
    int len = strlen(s);

    // loop through the string, swapping the characters at the
    // beginning and end until we reach the middle
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void reverse_string(char *s);

int main()
{
    char s[] = "Hello, World!";

    printf("Original string: %s\n", s);
    reverse_string(s);
    printf("Reversed string: %s\n", s);

    return 0;
}
