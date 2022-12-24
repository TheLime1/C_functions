// maybe m9rinehch.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *str, char *word)
{
    // split the string into words
    char *p = strtok(str, " ");
    int i = 0;

    // search for the word
    while (p != NULL)
    {
        if (strcmp(p, word) == 0)
        {
            // the word was found
            return i;
        }
        i++;
        p = strtok(NULL, " ");
    }

    // the word was not found
    return -1;
}

void search(char *str, char *word);

int main()
{
    char str[100];
    char word[100];
    int index;

    // read the string and word from the user
    printf("Enter the string: ");
    scanf("%[^\n]s", str);
    printf("Enter the word: ");
    scanf(" %[^\n]s", word);

    // search for the word in the string
    index = search(str, word);

    if (index == -1)
    {
        printf("The word was not found in the string.\n");
    }
    else
    {
        printf("The word was found at index %d in the string.\n", index);
    }

    return 0;
}
