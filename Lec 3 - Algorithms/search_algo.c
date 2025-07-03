#include <stdio.h>
#include <cs50.h>
#include <time.h>

int linear_search(int arr[], int N, int target)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int binary_search(int arr[], int N, int target)
{   
    int left = 0;
    int right = N - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// formarting to printout array
void print_array(int arr[], int N)
{
    printf("{");
    for (int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
        if (i < N - 1)
            printf(", ");
    }
    printf("}");
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int N = sizeof(arr) / sizeof(arr[0]);

    int target = get_int("target: ");

    // Time linear search
    clock_t start1 = clock();
    int result1 = linear_search(arr, N, target);
    clock_t end1 = clock();
    double time_linear = (double)(end1 - start1) / CLOCKS_PER_SEC;

    // Time binary search
    clock_t start2 = clock();
    int result2 = binary_search(arr, N, target);
    clock_t end2 = clock();
    double time_binary = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // Output result for linear
    printf("\n[Linear Search] ");
    if (result1 == -1)
    {
        printf("Not found %d in the given array ", target);
        print_array(arr, N);
        printf("\n");
    }
    else
    {
        printf("Found %d at index %d in array ", target, result1);
        print_array(arr, N);
        printf("\n");
    }

    // Output result for binary
    printf("[Binary Search] ");
    if (result2 == -1)
    {
        printf("Not found %d in the given array ", target);
        print_array(arr, N);
        printf("\n");
    }
    else
    {
        printf("Found %d at index %d in array ", target, result2);
        print_array(arr, N);
        printf("\n");
    }

    // Print time
    printf("\nTime taken:\n");
    printf("Linear Search: %.6f seconds\n", time_linear);
    printf("Binary Search: %.6f seconds\n", time_binary);

    return 0;
}
