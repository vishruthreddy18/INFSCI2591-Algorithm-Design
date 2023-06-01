def promising(i, weight, profit):
    totweight = 0
    bound = 0
    if weight < W:
        j = i + 1
        bound = profit
        totweight = weight
        while(j < n and totweight + w[j] <= W):
            totweight = totweight + w[j]
            bound = bound + p[j]
            j = j + 1
        k = j
        if k < n:
            bound = bound + (W - totweight) * pw[k]
        return bound > maxprofit
    return False

def knapsack(i, profit, weight):
    global maxprofit
    if profit > maxprofit and weight <= W:
        maxprofit = profit
        numbest = i
  
    if promising(i, weight, profit):
        include[i + 1] = 1
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1])
        include[i + 1] = 0
        knapsack(i + 1, profit, weight)

if __name__ == '__main__':
    n = 5
    W = 9
    maxprofit = numbest = 0

    bestset = [0 for x in range(n)]
    include = bestset

    p = [20, 30, 35, 12, 3]
    w = [2, 5, 7, 3, 1]
    pw = [10, 6, 5, 4, 3]
        
    knapsack(0, 20, 2)
    print(maxprofit)