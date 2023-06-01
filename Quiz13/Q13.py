def first_fit(weight, n, c):
    res = 0
    bin_rem = [0]*n
    for i in range(n):
        j = 0
        while( j < res):
            if (bin_rem[j] >= weight[i]):
                bin_rem[j] = bin_rem[j] - weight[i]
                break
            j+=1
        if (j == res):
            bin_rem[res] = c - weight[i]
            res= res+1
    return res
     
weight = []
n = int(input("Enter the number of items in the bin : "))
for i in range(0,n):
    ele = float(input())
    weight.append(ele)
print("The bin sizes: ",weight)
c = int(input("Each bin capacity is: "))
n = len(weight)
print("Number of bins required in First Fit : ",first_fit(weight, n, c))