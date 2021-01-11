# Recursive binary search algorithm (DAC) on Sorted Array

def binarySearch(arr, low, high, ele):

    if(high >= low):
        mid = low + (high-low)//2
        if(arr[mid] == ele):
            return mid
        elif(arr[mid] > ele):
            return binarySearch(arr, low, mid-1, ele)
        else:
            return binarySearch(arr, mid+1, high, ele)

    return -1


def isSorted(arr, arr_size):
    if(arr_size == 0 or arr_size == 1):
        return 1
    for i in range(1, arr_size):
        if(arr[i-1] > arr[i]):
            return 0
    return 1


arr_size = int(input("Enter the size of input array: "))
arr = []
print ("Enter the elements of array in ascending order :")
for i in range(arr_size):
    user_input = int(input())
    arr.append(user_input)

print("Entered array is :", arr)
check = isSorted(arr, arr_size)
if(check == 0):
    print("Input array is not sorted/ not in acending order!!")
    exit()

ele = int(input("Enter the element to search in array: "))
index = binarySearch(arr, 0, arr_size-1, ele)
if(index == -1):
    print(ele,"is not found in Array !!")
else:
    print(ele,"is present at index :",index)

