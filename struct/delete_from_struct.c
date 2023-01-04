#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Define a struct to hold information about a person
struct Person
{
    char name[MAX_LENGTH];
    int age;
};

// Function definition for "delete_element"
// Takes a pointer to a Person struct and the index of the element to be deleted as arguments
// Deletes the element by shifting the elements after it one position to the left
void delete_element(struct Person *people, int index)
{
    int i;
    int num_people = sizeof(people) / sizeof(struct Person); // calculate the number of people in the struct array

    // Shift the elements after the element to be deleted one position to the left
    for (i = index; i < num_people - 1; i++)
    {
        strcpy(people[i].name, people[i + 1].name);
        people[i].age = people[i + 1].age;
    }
}

// Function declaration for "delete_element"
void delete_element(struct Person *people, int index);

int main()
{
    // Create an array of Person structs
    struct Person people[5] = {{"Alice", 30}, {"Bob", 35}, {"Charlie", 40}, {"Dave", 45}, {"Eve", 50}};

    // Call the "delete_element" function to delete the second element (index 1)
    delete_element(people, 1);

    return 0;
}
