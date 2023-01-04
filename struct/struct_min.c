#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
    int value;
};

void find_min(struct Data *data, int size, int *min)
{
    *min = data[0].value;
    for (int i = 1; i < size; i++)
    {
        if (data[i].value < *min)
        {
            *min = data[i].value;
        }
    }
}

int main()
{
    struct Data data[] = {{1}, {2}, {3}, {4}, {5}};
    int size = sizeof(data) / sizeof(data[0]);
    int min;
    find_min(data, size, &min);
    printf("The minimum value is: %d\n", min);
    return 0;
}
