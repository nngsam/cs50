#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc < 3) // ít nhất: ./search target num1
    {
        printf("Usage: ./search <target> <num1> <num2> ...\n");
        return 1;
    }

    int target = atoi(argv[1]);
    int array_len = argc - 2;

    int numbers[array_len];
    for (int i = 0; i < array_len; i++)
    {
        numbers[i] = atoi(argv[i + 2]);
    }

    // Linear search
    for (int i = 0; i < array_len; i++)
    {
        if (numbers[i] == target)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
