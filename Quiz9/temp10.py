maxprofit = 0
from collections import deque

# class Queue:
#     def _init_(self):
#         self.items = deque([], 45)

#     def isEmpty(self):
#         return self.items == deque([], 45)

#     def enqueue(self, item):
#         self.items.append(item)

#     def dequeue(self):
#         return self.items.popleft()

#     def size(self):
#         return len(self.items)

class Node:
    def __init__(self, level, profit, weight):
        self.level = level
        self.profit = profit
        self.weight = weight
        self.items = []
        


def knapsack_bfs(n, p, w, W, maxprofit):
  Q = deque([], n)
  v = Node(0, 0, 0)
#   v.create_node(0,0,0)
  u = Node(0, 0, 0)
  #maxprofit = 0
  Q.append(v)
  while(len(Q) > 0):
    v = Q[0]
    Q.popleft()
    u.level = v.level
    print("u.level" + str(u.level))
    print("u.wt" + str(u.weight))
    print("u.pt" + str(u.profit))
    
    u.level = v.level
    u.weight = v.weight + w[u.level]
    u.profit = v.profit + p[u.level]
    if(u.weight <= W and u.profit > maxprofit):
      print("here")
      maxprofit = u.profit
    if(bound(u) > maxprofit):
      Q.append(u)
      print(Q)
    u.weight = v.weight
    u.profit = v.profit
    if(bound(u) > maxprofit):
      Q.append(u)
  
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
    if k < n:
      result = result + (W - totweight)*pw[k]
    return result

n = 5
W = 13
p = [20, 30, 35, 12, 3]
w = [2, 5, 7, 3, 1]
pw = [10, 6, 5, 4, 3]
knapsack_bfs(n, p, w, W, 0)
print(maxprofit)