#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *str, char *word)
{
    int i, j, str_len, word_len;
    str_len = strlen(str);
    word_len = strlen(word);

    for (i = 0; i < str_len - word_len + 1; i++)
    {
        for (j = 0; j < word_len; j++)
        {
            if (str[i + j] != word[j])
            {
                break;
            }
        }
        if (j == word_len)
        {
            // the word was found
            return i;
        }
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
