def find(n, arr):
    if arr[0] > arr[1]:
        small = arr[1]
        large = arr[0]
    else:
        small = arr[0]
        large = arr[1] 

    for i in range(1, n, 2):
        if arr[i] >= arr[i + 1]:
            if arr[i+1] < small:
                small = arr[i+1]
            if arr[i] > large:
                large = arr[i]
        else:
            if arr[i] < small:
                small = arr[i]
            if arr[i+1] > large:
                large = arr[i+1]

    print(small, end = ",")
    print(large)

if __name__ == "__main__":
    n = 7
    arr = [1, 8, 3, 9, 6, 5, 4]

    # n = 5
    # arr = [9, 8, 7, 6, 10]

    # n = 9
    # arr = [11,2,3,4,5,7,8,9,10]

    find(n, arr)