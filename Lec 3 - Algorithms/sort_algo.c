#include <stdio.h>
#include <cs50.h>
#include <time.h>


void swap(int arr[], int i, int j)
{
    int temp = arr[i]; 
    arr[i] = arr[j];
    arr[j] = temp;
}

// Bubble sort
void bubble_sort(int arr[], int N)
{
    int swap_counter = -1;

    while (swap_counter != 0)
    {
        swap_counter = 0;

        for (int i = 0; i < N-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr, i, i+1);
                swap_counter ++; 
            }
        }
    }
}

// Selection sort
void selection_sort(int arr[], int N)
{

}
// Merge sort
void merge_sort(int arr[], int N)
{

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
void sort_and_report(const char *sort_type, void(*sort_func)(int[], int), int arr[], int N)
{
    clock_t start = clock();
    sort_func(arr, N);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;  // actual time taken

    // search result
    printf("[%s] ==> ", sort_type);
    printf("sorted array: ");
    print_array(arr, N);
    printf("\n");

    // time
    printf("Time taken by %s: %.6f seconds\n\n", sort_type, elapsed_time);
}


int main(void)
{
    int arr[] = {10, 3, 2, 11, 1, 10};
    int N = sizeof(arr) / sizeof(arr[0]);

    sort_and_report("Bubble Sort", bubble_sort, arr, N);
    return 0;
}
