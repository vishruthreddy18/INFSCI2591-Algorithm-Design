def count_comp(arr):
  print()
  print("Original Array: ")
  print(arr)
  
  table = []
  count = []
  for a in arr:
    c1 = 0
    c2 = 0
    for i in range(len(arr)):
      if arr[i] < a:
        c2 += 1
    while(c2 in table):
      c2 += 1
    table.append(c2)
  print("Table for the counts: ")
  print(table)
  new = [0 for x in range(len(arr))]
  for i in range(len(arr)):
    new[table[i]] = arr[i]
  
  print("Sorted Array: ")
  print(new)
  print()

arr1 = [62, 31, 84, 96, 19, 47]
arr2 = [1, 4, 1, 2, 7, 5, 2]
arr3 = [5, 2, 9, 5, 2, 3, 5]

if __name__ == "__main__":
    count_comp(arr1)
    count_comp(arr2)
    count_comp(arr3)
