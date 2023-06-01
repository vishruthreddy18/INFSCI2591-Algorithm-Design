def count_sort(arr):
  n = len(arr)
  table = []
  
  print("Original Array:", end = " ")
  print(arr)
  
  for j in arr:
    c = 0
    for i in range(n):
      if arr[i] < j:
        c = c + 1
    while(c in table):
      c = c + 1
    table.append(c)
  print("Table for the counts:", end = " ")
  print(table)
  sorted_arr = [0 for x in range(n)]
  for i in range(n):
    sorted_arr[table[i]] = arr[i]
  
  print("Sorted Array:", end = " ")
  print(sorted_arr)

arr1 = [62, 31, 84, 96, 19, 47]
arr2 = [1, 4, 1, 2, 7, 5, 2]
arr3 = [5, 2, 9, 5, 2, 3, 5]

if __name__ == "__main__":
  print()
  print("Example Test Case: ")
  count_sort(arr1)
  print()
  print("Test Case 1: ")
  count_sort(arr2)
  print()
  print("Test Case 2: ")
  count_sort(arr3)
