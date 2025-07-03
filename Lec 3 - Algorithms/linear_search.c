#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>


int main(int argc, char *argv[])
{
    if (argc < 3) // ít nhất: ./search target num1
    {
        fprintf(stderr, "error: not enough arguments\n");
        fprintf(stderr, "usage: ./linear_search <target> <num1> <num2> ...\n");
        // return 1;
        exit(EXIT_FAILURE);  // giống raise Exception
    }

    int target = atoi(argv[1]);
    int array_len = argc - 2;  // độ dài của mảng 

    int numbers[array_len];
    for (int i = 0; i < array_len; i++) 
    {
        numbers[i] = atoi(argv[i + 2]);  // chuyển đổi phần còn lại thành số và lưu vào mảng 
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