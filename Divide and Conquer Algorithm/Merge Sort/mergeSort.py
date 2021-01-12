# Python program for implementation of MergeSort

# Merges two subarrays of arr[].
# First subarray is arr[l..m]
# Second subarray is arr[m+1..r]
def merge(arr, low, mid, high):
    n1 = mid - low + 1
    n2 = high - mid

    # create temp arrays
    L = [0] * (n1)
    R = [0] * (n2)

    # Copy data to temp arrays L[] and R[]
    for i in range(0, n1):
        L[i] = arr[low + i]

    for j in range(0, n2):
        R[j] = arr[mid + 1 + j]

        # Merge the temp arrays back into arr[low...high]
    i = 0  # Initial index of first subarray
    j = 0  # Initial index of second subarray
    k = low # Initial index of merged subarray

    while (i < n1 and j < n2):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Copy the remaining elements of L[], if there
    # are any
    while (i < n1):
        arr[k] = L[i]
        i += 1
        k += 1

    # Copy the remaining elements of R[], if there
    # are any
    while (j < n2):
        arr[k] = R[j]
        j += 1
        k += 1


# low is for left index and high is right index of the sub-array of arr to be sorted
def mergeSort(arr, low, high):
    if (low < high):
        mid = (low + high) // 2

        # Sort first and second halves
        mergeSort(arr, low, mid)
        mergeSort(arr, mid + 1, high)
        merge(arr, low, mid, high)


arr_size = int(input('Enter the input array size : '))
arr = []

print('Enter the elements of array :')
for i in range(arr_size):
    input_data = int(input())
    arr.append(input_data)

print('Input array :',arr)

mergeSort(arr, 0, arr_size - 1)

print('\n\nSorted array :', arr)
