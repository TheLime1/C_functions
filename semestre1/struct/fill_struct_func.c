#include <stdio.h>
#include <stdlib.h>

// Declare a type alias for a struct that represents a person
typedef struct
{
    char *name;
    int age;
} Person;

// Declare a function that returns a Person
Person create_person(char *name, int age);

int main()
{
    // Create a person using the create_person function
    Person p = create_person("John", 30);

    // Print the person's name and age
    printf("Name: %s\nAge: %d\n", p.name, p.age);

    return 0;
}

// Define the create_person function
Person create_person(char *name, int age)
{
    Person p;
    p.name = name;
    p.age = age;
    return p;
}