// Implementation of QuickSort


#include<stdio.h>


// function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


// function for partitioning of array in quick-sort algorithm
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // considering first element as pivot element
    int start = low, end = high;
    while(start < end)
    {
        while( start < high && arr[start] <= pivot) {
            start++;
        }

        while( end > low && arr[end] > pivot) {
            end--;
        }

        if(start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);

    return end;
}


// function for performing quick-sort on array
void quickSort(int arr[], int low, int high)
{
    if (low < high) // If there are more than one element
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}


// Function to print an array
void printArray(int arr[], int arr_size)
{
    for (int i=0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
}



// main function
int main()
{
    int arr_size;
    printf("\n Enter the size of input array : ");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("\n Enter the elements of array :\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n Entered array : ");
    printArray(arr, arr_size);
    quickSort(arr, 0, arr_size-1);
    printf("\n Sorted array : ");
    printArray(arr, arr_size);

    return 0;
}
