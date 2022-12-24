// searching for a name in struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Person
{
    char name[100];
    int age;
};

int search(struct Person *people, int size, char *name)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void search(struct Person *people, int size, char *name);

int main()
{
    struct Person people[SIZE];
    char name[100];
    int index;

    // fill the struct array with some values
    strcpy(people[0].name, "Alice");
    people[0].age = 21;
    strcpy(people[1].name, "Bob");
    people[1].age = 25;
    strcpy(people[2].name, "Charlie");
    people[2].age = 30;
    // ...

    // read the name to be searched from the user
    printf("Enter the name to be searched: ");
    scanf("%s", name);

    index = search(people, SIZE, name);
    if (index == -1)
    {
        printf("The name was not found\n");
    }
    else
    {
        printf("The name was found at index %d\n", index);
    }

    return 0;
}
