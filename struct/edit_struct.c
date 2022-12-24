#include <stdio.h>

void edit_element(struct Person *person, int index)
{
    // ask the user for the new name and age of the person
    printf("Enter the new name and age of the person: ");
    scanf("%s %d", person[index].name, &person[index].age);
}

void edit_element(struct Person *person, int index);

int main()
{
    struct Person people[10];

    // fill the array with some values
    for (int i = 0; i < 10; i++)
    {
        sprintf(people[i].name, "Person %d", i);
        people[i].age = i;
    }

    // print the original array
    printf("Original array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    // read the index of the element to be edited from the user
    int index;
    printf("Enter the index of the element to be edited: ");
    scanf("%d", &index);

    // edit the element
    edit_element(people, index);

    // print the modified array
    printf("Modified array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    return 0;
}
