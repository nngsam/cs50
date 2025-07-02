
#include <stdio.h>
#include <cs50.h>

int linear_search(int arr[], int N, int target)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == target)
            return i;
    return -1;
}


int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = get_int("target: \n");
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = linear_search(arr, N, target);
    (result == -1)
        ? printf("not found")
        : printf("found at index %d", result);
    return 0;
}