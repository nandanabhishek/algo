// Merge Sort (DAC/Recursive Approach)
#include <stdio.h>
#include <malloc.h>



// function for Merging Arrays
// A – input array, low – lower index, high – higher index
void Merge(int arr[], int low, int mid, int high)
{

    int i=low, j=mid+1, k=low, B[high - low + 1]; // B is a temporary array

    // k used for indexing array b;
    // i and j used for indexing on array A

    while (i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            B[k]=arr[i];
            k=k+1;
            i=i+1;
        }
        else {
            B[k]=arr[j];
            k=k+1;
            j=j+1;
        }
    }

    while (i <= mid) { // Copy the remaining elements in first half of A to B
        B[k] = arr[i];
        k = k + 1;
        i = i + 1;
    }


    while (j <= high) { // Copy the remaining elements in second half of A to B
        B[k] = arr[j];
        k = k + 1;
        j = j + 1;
    }

    //copy the sorted elements into array A into its respective positions from Array B
    for(k=low; k <= high; k++) {
        arr[k] = B[k];
    }
    free(B);
}



// function for MergeSort
void MergeSort(int A[], int low, int high) // A – input array, low – lower index, high – higher index
{
    if (low < high) // the array has at least two elements
    {
        int mid = (low + high) / 2;

        // call the merge sort on first half of the elements of A
        MergeSort(A, low, mid);


        //  call the merge sort on second half of the elements of A
        MergeSort(A, mid+1, high);

        // Merge the sorted elements of the first half and second half
        Merge(A, low, mid, high);

    }
}


/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf(" %d ", A[i]);
    printf("\n");
}



int main()
{
    int size;
    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\n Enter the elements of the array :\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n Entered Array : " );
    printArray(arr, size);

    MergeSort(arr, 0, size-1);

    printf("\n Sorted array : ");
    printArray(arr, size);

    return 0;
}
