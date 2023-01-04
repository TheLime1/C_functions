#include <stdio.h>
#include <string.h>

// Define the struct and its variables
struct Person
{
    char name[20];
    int age;
};

// Function that takes a pointer to the struct as an argument and prints its values
void printPerson(struct Person *p)
{
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main()
{
    // Create an instance of the struct and assign values to its variables
    struct Person person = {"John", 30};

    // Call the function that prints the struct, passing the address of the struct instance as an argument
    printPerson(&person);

    return 0;
}
