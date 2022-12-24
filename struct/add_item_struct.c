#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Person
{
    char name[100];
    int age;
};

void add_to_struct(struct Person *people, int size, char *name, int age)
{
    // check if the struct is full
    if (size == SIZE)
    {
        printf("Error: Struct is full. Cannot add more elements.\n");
        return;
    }

    // add the new element to the struct
    strcpy(people[size].name, name);
    people[size].age = age;
}

void add_to_struct(struct Person *people, int size, char *name, int age);

int main()
{
    struct Person people[SIZE];
    char name[100];
    int age;

    // add some elements to the struct
    add_to_struct(people, 0, "John", 20);
    add_to_struct(people, 1, "Jane", 22);
    add_to_struct(people, 2, "Bob", 25);

    // read the element to be added from the user
    printf("Enter the name and age of the person to be added: ");
    scanf("%s %d", name, &age);

    // add the new element to the struct
    add_to_struct(people, 3, name, age);

    return 0;
}
