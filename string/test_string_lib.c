#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns the length of a string
int string_length(char *s)
{
    return strlen(s);
}

// copies the contents of one string to another
void string_copy(char *dest, char *src)
{
    strcpy(dest, src);
}

// copies the specified number of characters from one string to another
void string_ncopy(char *dest, char *src, int n)
{
    strncpy(dest, src, n);
}

// concatenates (joins) two strings
void string_concat(char *dest, char *src)
{
    strcat(dest, src);
}

// concatenates the specified number of characters from one string to the end of another
void string_nconcat(char *dest, char *src, int n)
{
    strncat(dest, src, n);
}

// compares two strings and returns an integer indicating their lexicographic ordering
int string_compare(char *s1, char *s2)
{
    return strcmp(s1, s2);
}

int string_length(char *s);
void string_copy(char *dest, char *src);
void string_ncopy(char *dest, char *src, int n);
void string_concat(char *dest, char *src);
void string_nconcat(char *dest, char *src, int n);
int string_compare(char *s1, char *s2);

int main()
{
    char s1[] = "Aymen";
    char s2[] = "Hmani";
    char dest[20];

    printf("s1 length: %d\n", string_length(s1));
    printf("s2 length: %d\n", string_length(s2));

    string_copy(dest, s1);
    printf("Copied s1 to dest: %s\n", dest);

    string_ncopy(dest, s2, 3);
    printf("Copied 3 characters of s2 to dest: %s\n", dest);

    string_concat(dest, s1);
    printf("Concatenated s1 to dest: %s\n", dest);

    string_nconcat(dest, s2, 3);
    printf("Concatenated 3 characters of s2 to dest: %s\n", dest);

    printf("s1 and s2 compared: %d\n", string_compare(s1, s2));

    return 0;
}
