class Node:
    def __init__(self, level, profit, weight):
        self.level = level
        self.profit = profit
        self.weight = weight
        self.items = []
        
class Node_:
    def __init__(self, level, profit, weight):
        pass

def knapsack_bfs():
  Q = []
  v = Node(0, 0, 0)
  u = Node_(0, 0, 0)
  maxprofit = 0
  Q.append(v)
  while(Q):
    v = Q[0]
    Q.pop(0)
    
    u.level = v.level + 1
    u.weight = v.weight + w[u.level-1]
    u.profit = v.profit + p[u.level-1]
    if(u.weight <= W and u.profit > maxprofit):
      maxprofit = u.profit
    if(bound(u) > maxprofit):
      Q.append(u)
    u.weight = v.weight
    u.profit = v.profit
    if(bound(u) > maxprofit):
      Q.append(u)
  return maxprofit
  
def bound(u):
  
  if u.weight > W:
    return 0
  else:
    result = u.profit
    j = u.level + 1
    totweight = u.weight
    while(j<n and totweight + w[j] <= W):
      totweight = totweight + w[j]
      result = result + p[j]
      j += 1
    k = j
    if k <= n:
      result = result + (W - totweight)*p[k-1]/w[k-1]
    return result

n = 5
W = 13
p = [20, 30, 35, 12, 3]
w = [2, 5, 7, 3, 1]
pw = [10, 6, 5, 4, 3]
print(knapsack_bfs())