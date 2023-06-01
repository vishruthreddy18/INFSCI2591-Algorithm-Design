from typing import DefaultDict


INT_MAX = 2147483647

def tsp_greedy(tsp):
  sum = 0
  counter = 0
  j = 0
  i = 0
  s = set()
  s.add(0)
  route = [0] * len(tsp)
  while i < len(tsp):
    m = INT_MAX
    if counter == len(tsp) - 1:
      break
    j = 0
    ind = 0
    while j < len(tsp[i]):
      if i != j and (j not in s):
        if tsp[i][j] < m:
          m = tsp[i][j]
          ind = j
      j += 1 
    sum += m
    s.add(ind)
    i = ind
    counter += 1
  sum += tsp[ind][0]
  print("The minimum cost is: ", sum)

def tsp_heuristics(G,s):
	visited = []
	src = s
	cost = 0
	while s not in visited:

		edges = G[s]
		min_weight = -1
		min_node = -1
		visited.append(s)
		for (i, j) in enumerate(edges):

			if (min_weight == -1) and (i not in visited):
				min_weight = j
				min_node = i

			elif (min_weight != -1) and (j < min_weight) and (i not in visited):
				min_weight = j
				min_node = i
		if min_node != -1:
			s = min_node
		if min_weight != -1:
			cost += min_weight
	cost += G[s][src]
	print("The total cost is:", cost)

if __name__ == "__main__":
  G = [[-1, 60, 100, 50, 90],[60, -1, 70, 40, 30 ],[100, 70, -1, 65, 55] ,[50, 40, 65, -1,110 ],[90, 30, 55, 110, -1]]  #Test Case -1
  tsp = [[-1, 10, 15, 20], [10, -1, 35, 25], [15, 35, -1, 30], [20, 25, 30, -1]] #Test Case-2
  tsp_greedy(G)
  tsp_greedy(tsp)
  tsp_heuristics(G,0)
  tsp_heuristics(tsp,0)