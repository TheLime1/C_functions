#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_case(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
            continue;
        }
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }
}

void convert_case(char *s);

int main()
{
    char s[100];
    gets(s);
    convert_case(s);
    puts(s);
    return 0;
}
