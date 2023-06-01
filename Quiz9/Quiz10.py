# from collections import deque
import queue

class Node:
    def __init__(self, level, profit, weight):
        self.level = level
        self.profit = profit
        self.weight = weight
        self.items = []


def knapsack_bfs(n, p, w, W, maxprofit):
  Q = queue.Queue()
  v = Node(0,0,0)
  u = Node(0,0,0)
  maxprofit = 0
  Q.put(v)
  while(not Q.empty()):
    v = Q.queue[0]
    Q.get()
    print(v)
    u.level = v.level
    u.profit = v.profit + p[u.level]
    u.weight = v.weight + w[u.level]
    if(u.weight <= W and u.profit > maxprofit):
      maxprofit = u.profit
    if(bound(u) > maxprofit):
      Q.put(u)
    u.weight = v.weight
    u.profit = v.profit
    if(bound(u) > maxprofit):
      Q.put(u)
  return maxprofit
  
def bound(u):
  if u.weight >= W:
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
      result = result + (W - totweight)*(p[k]/w[k])
    return result

n = 5
W = 13
p = [20, 30, 35, 12, 3]
w = [2, 5, 7, 3, 1]
# maxprofit = 0
print(knapsack_bfs(n, p, w, W, 0))

