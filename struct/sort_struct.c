#include <stdio.h>

#define SIZE 10

struct Person
{
    char name[100];
    int age;
};

void bubble_sort(struct Person array[], int size)
{
    int i, j;
    struct Person temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j].age > array[j + 1].age)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void bubble_sort(struct Person array[], int size);

int main()
{
    struct Person array[SIZE];
    int i;

    // fill the array with some values
    for (i = 0; i < SIZE; i++)
    {
        sprintf(array[i].name, "Person %d", i + 1);
        array[i].age = rand() % 100;
    }

    // print the original array
    printf("Original array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Name: %s, Age: %d\n", array[i].name, array[i].age);
    }

    // sort the array
    bubble_sort(array, SIZE);

    // print the sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Name: %s, Age: %d\n", array[i].name, array[i].age);
    }

    return 0;
}
