#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a person
struct Person
{
    char name[100];
    int age;
};

// Function definition for "fill_struct"
// Takes a pointer to a Person struct as an argument and fills the struct using scanf
void fill_struct(struct Person *person)
{
    // fill the struct using scanf
    printf("Enter the name and age of the person: ");
    scanf("%s %d", person->name, &person->age);
}

// Function declaration for "fill_struct"
void fill_struct(struct Person *person);

// Function definition for "print_struct"
// Takes a pointer to a Person struct as an argument and prints the struct
void print_struct(struct Person *person)
{
    // print the struct
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

// Function declaration for "print_struct"
void print_struct(struct Person *person);

int main()
{
    struct Person person;

    // Call the "fill_struct" function to fill the struct
    fill_struct(&person);

    // Call the "print_struct" function to print the struct
    print_struct(&person);

    return 0;
}
