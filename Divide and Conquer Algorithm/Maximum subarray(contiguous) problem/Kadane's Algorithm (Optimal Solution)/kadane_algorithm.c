#include<stdio.h>

int maxSubArraySum(int arr[], int arr_size)
{
    int global_max = arr[0], curr_max = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        curr_max = curr_max + arr[i];
        if(curr_max < arr[i]) {
            curr_max = arr[i] ;
        }

        if (global_max < curr_max) {
            global_max = curr_max ;
        }
    }
    return global_max ;
}


int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr_size = sizeof(arr)/sizeof(arr[0]); // way of determining the size of array
    int max_sum = maxSubArraySum(arr, arr_size);
    printf("Maximum contiguous sum is : %d", max_sum);
    return 0;
}
