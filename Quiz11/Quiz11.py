def partition(arr, l, h):
    i = l - 1
    x = arr[h]
    
    for j in range(l, h):
        if arr[j] <= x:
            i += 1
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
            
    temp = arr[i + 1]
    arr[i + 1] = arr[h]
    arr[h] = temp
    
    return i + 1

def quicksort(arr, l, h):
    qsstack = [0] * (h - l + 1)
    
    top = 0
    qsstack[top] = l
    top += 1
    qsstack[top] = h
    
    while top >= 0:
        h = qsstack[top]
        top -= 1
        l = qsstack[top]
        top -= 1
        
        p = partition(arr, l, h)
        
        if h > p + 1:
            top += 1
            qsstack[top] = p + 1
            top += 1
            qsstack[top] = h
        
        if l < p - 1:
            top += 1
            qsstack[top] = l
            top += 1
            qsstack[top] = p - 1
            
if __name__ == "__main__":
    # arr = [4, 3, 5, 2, 1, 3, 2, 3]
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    # arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    n = len(arr)
    
    print("Array before applying Quick Sort:")
    print(arr, end = "\n")
    
    quicksort(arr, 0, n - 1)
    
    print ("\nArray after applying Quick Sort:")
    print(arr)