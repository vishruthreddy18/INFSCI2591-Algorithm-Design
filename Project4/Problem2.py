#%%
from collections import defaultdict
import time
import random
import matplotlib.pyplot as plt

def generate(n):
  graph = dict()
  for i in range(1, n + 1):
    vi = random.sample(range(1, n + 1), random.randint(0, n))
    if i in vi:
      vi.remove(i)
    vi.sort()
    graph[i] = vi
  return graph

def graphSets(graph):
	if(len(graph) == 0):
		return []

	if(len(graph) == 1):
		return [list(graph.keys())[0]]
	
	vCurr = list(graph.keys())[0]
	
	graph2 = dict(graph)
	
	del graph2[vCurr]

	res1 = graphSets(graph2)
	
	for v in graph[vCurr]:
		
		if(v in graph2):
			del graph2[v]
	
	res2 = [vCurr] + graphSets(graph2)
	
	if(len(res1) > len(res2)):
		return res1
	return res2

def find_clique(graph):
    
    cl =[]
    vertices = list(graph.keys())
    for ve in vertices:
      clique = []
      clique.append(ve)
      for v in vertices:
          if v in clique:
              continue
          isNext = True
          for u in clique:
              if u in graph[v]:
                  continue
              else:
                  isNext = False
                  break
          if isNext:
              clique.append(v)

      cl.append((len(clique), sorted(clique)))
    (cin, clique) = max(cl)
    return clique


# Driver Code
# graph = dict([])

# # graph[1] = []
# # graph[2] = [3,5]
# # graph[3] = [2,6]
# # graph[4] = [5]
# # graph[5] = [4,6]
# # graph[6] = [5]
# # graph[7] = [8,9]
# # graph[8] = [7,9]
# # graph[9] = [7,8]

# # graph[1] = [4]
# # graph[2] = [3, 5, 6]
# # graph[3] = [2, 5, 6]
# # graph[4] = [1, 7, 8]
# # graph[5] = [2, 3, 6]
# # graph[6] = [2, 3, 5]
# # graph[7] = [4, 8]
# # graph[8] = [4, 7, 9]
# # graph[9] = [8]

# maxIndSet = graphSets(graph)
# clique = find_clique(graph)
# # Prints the Result
# print("Independent Set:", maxIndSet)
# print("Max Clique:", clique)

tis = []
tcl = []
n = [i for i in range(1, 100)]

for x in n:
  graph = generate(x)

  t1 = time.time()
  maxIndSet = graphSets(graph)
  t2 = time.time()

  tis.append(t2 - t1)

  t3 = time.time()
  clique = find_clique(graph)
  t4 = time.time()

  tcl.append(t4 - t3)

# Prints the Result
for i in maxIndSet:
	print(i, end =" ")
 
print(tis)
print(tcl)

plt.ylabel("Execution Time")
plt.xlabel("n")
plt.plot(n, tis)    
plt.plot(n, tcl)
plt.legend(["Independent Set", "Max Clique"])
#%%