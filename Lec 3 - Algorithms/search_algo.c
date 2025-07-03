#include <stdio.h>
#include <cs50.h>
#include <time.h>


// Linear search
int linear_search(int arr[], int N, int target)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

// Binary search
int binary_search(int arr[], int N, int target)
{   
    int left = 0, right = N - 1;
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


void print_array(int arr[], int N)
{
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
        if (i < N - 1) printf(", ");
    }
    printf("]");
}

// running time and comparing
void search_and_report(const char *search_type, int (*search_func)(int[], int, int), int arr[], int N, int target)
{
    clock_t start = clock();
    int result = search_func(arr, N, target);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;  // actual time taken

    // search result
    printf("[%s] \n", search_type);
    if (result == -1)
    {
        printf("Not found %d in array ", target);
    }
    else
    {
        printf("Found %d at index %d in array ", target, result);
    }
    print_array(arr, N);
    printf("\n");

    // time
    printf("Time taken by %s: %.6f seconds\n\n", search_type, elapsed_time);
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int N = sizeof(arr) / sizeof(arr[0]);
    int target = get_int("target: ");

    search_and_report("Linear Search", linear_search, arr, N, target);
    search_and_report("Binary Search", binary_search, arr, N, target);

    return 0;
}
