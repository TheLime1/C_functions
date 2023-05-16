#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
void count_words_phrases(const char *str);

// function definition
void count_words_phrases(const char *str)
{
    int words = 0, phrases = 0;
    int i;

    // iterate through the string
    for (i = 0; i < strlen(str); i++)
    {
        // count the words
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            words++;
        }

        // count the phrases
        if (str[i] == '.')
        {
            phrases++;
        }
    }

    // add 1 to the word count to account for the last word in the string
    words++;

    printf("Number of words: %d\n", words);
    printf("Number of phrases: %d\n", phrases);
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]s", str); // read the string from the user, including whitespace

    count_words_phrases(str);

    return 0;
}
