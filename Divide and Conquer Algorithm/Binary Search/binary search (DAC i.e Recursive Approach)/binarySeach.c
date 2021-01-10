// C program to implement recursive Binary Search (Divide and Conquer)
#include <stdio.h>

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1

int binarySearch(int arr[], int low, int high, int ele)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == ele) {
            return mid;
        }

        // If element is smaller than mid,
        // then it can only be present in left subarray
        else if (arr[mid] > ele) {
            return binarySearch(arr, low, mid - 1, ele);
        }

        // Else the element can only be present 
        // in right subarray
        else {
            return binarySearch(arr, mid + 1, high, ele);
        }

    }

    // We reach here when element is not 
    // present in array
    return -1;

}


//Function to print the array
void printArray(int arr[], int arr_size)
{
    for (int i=0; i < arr_size; i++) {
        printf("%d   ", arr[i]);
    }
}


int isSorted(int arr[], int arr_size)
{
    // if there is none or one element in array
    if (arr_size == 0 || arr_size == 1) {
        return 1;
    }
    for(int i=1; i < arr_size; i++) {
        if(arr[i-1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}


int main()
{
    int arr_size, low = 0, ele;
    printf("\n Enter the input array size : ");
    scanf("%d", &arr_size);
    int arr[arr_size]; // declaring the array

    printf("\n Enter the elements of array in Sorted order(Ascending Order) :\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n Entered array is : ");
    printArray( arr, arr_size);

    int check = isSorted(arr, arr_size);

    if( check == 0) {
        printf("\n\n ---- The array entered is not in ascending order!!! ----");
        return 0;
    }

    printf("\n Enter the element to search from array: ");
    scanf("%d", &ele);

    int index = binarySearch(arr, low, arr_size-1, ele);
    if(index == -1) {
        printf("\n %d is not found in Array !", ele);
    }
    else {
        printf("\n %d is present at index : %d ", ele, index);
    }

    return 0;
    
}
