# function for finding maximum sum of contiguous array in an Array

def maxArraySum(arr):
    global_max = curr_max = arr[0]

    for i in range(1, len(arr)):
        
        curr_max = max(curr_max, curr_max + arr[i])
        
        if(curr_max > global_max):
            global_max = curr_max

    return global_max



arr = [-2, 3, 2, -1]
maxSum = maxArraySum(arr)
print('The maximum contiguous array sum is :',maxSum)
