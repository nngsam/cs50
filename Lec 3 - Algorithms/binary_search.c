#include <stdio.h>
#include <stdlib.h>


int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid; // found, return index
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: ./binary_search <target> <sorted_num1> <sorted_num2> ...\n");
        return 1;
    }

    int target = atoi(argv[1]);
    int n = argc - 2;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        numbers[i] = atoi(argv[i + 2]);
    }

    // call binary search
    int index = binary_search(numbers, n, target);

    if (index != -1)
    {
        printf("Found at index %d\n", index);
        return 0;
    }
    else
    {
        printf("Not found\n");
        return 1;
    }
}
