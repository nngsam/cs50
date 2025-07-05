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
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i+1; j < N; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min !=  i)
        {
            swap(arr, i, min);
        }
    }
}

// Insertion sort
void insertion_sort(int arr[], int N)
{
    for (int i=0; i < N; i++)
    {
        for (int j=i+1; j < N; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, i, j);
            }
        }
    }

}

//// Merge Sorting
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right)
{
    // left part is purposedly smaller if odd 
    // a single-element array must necessarily be sorted
    // step 1: sort left part
    // step 2: sort right part
    // step 3: merge the two sorted parts (the simplest case is when the number of elements is two, merge 2 parts with each has onlhy one number)

    // base case: if the array has only one element, it is already sorted

    if (left >= right) 
        return;
    
    int mid = (left + right) / 2;
    
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    
    merge(arr, left, mid, right);

}
// Wrapper for merge sort to match (int[], int) signature
void merge_sort_wrapper(int arr[], int N)
{
    merge_sort(arr, 0, N - 1);
}


void copy_array(int unsorted[], int sorted[], int N)
{
    for (int i = 0; i < N; i++)
    {
        sorted[i] = unsorted[i];
    }
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
void sort_and_report(const char *sort_type, void(*sort_func)(int[], int), int unsorted[], int N)
{
    int arr_dest[N];
    copy_array(unsorted, arr_dest, N);
    
    clock_t start = clock();
    sort_func(arr_dest, N);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;  // actual time taken

    // search result
    printf("[%s] ==> ", sort_type);
    printf("sorted array: ");
    print_array(arr_dest, N);
    printf("\n");

    // time
    printf("Time taken by %s: %.6f seconds\n\n", sort_type, elapsed_time);
}


int main(void)
{
    int arr[] = {10, 3, 2, 11, 1, 10, 1, 4, 5, 2, 5, 21};
    int arr1[] = {5, 2, 1, 3, 6, 4};
    int N = sizeof(arr) / sizeof(arr[0]);

    sort_and_report("Bubble Sort", bubble_sort, arr, N);
    sort_and_report("Selection Sort", selection_sort, arr, N);
    sort_and_report("Insertion Sort", insertion_sort, arr, N);
    sort_and_report("Merge Sort", merge_sort_wrapper, arr, N);

    return 0;
}