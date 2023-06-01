cnt = 0

def isSafe(graph, color):

	for i in range(6):
		for j in range(i + 1, 6):
			if (graph[i][j] and color[j] == color[i]):
				return False
	return True

def graphColoring(graph, m, i, color):

	if (i == 6):

		if (isSafe(graph, color)):

			printSolution(color)
		return False

	for j in range(1, m + 1):
		color[i] = j

		if (graphColoring(graph, m, i + 1, color)):
			break
		color[i] = 0
	return False

def printSolution(color):
	global cnt 
	cnt = cnt + 1
	for i in range(6):
		print(color[i], end=" ")
	print()

if __name__ == '__main__':

	graph = [
     	[ 0, 1, 0, 1, 0, 0 ],
		[ 1, 0, 1, 0, 1, 0 ],
		[ 0, 1, 0, 0, 0, 1 ],
		[ 1, 0, 0, 0, 1, 0 ],
		[ 0, 1, 0, 1, 0, 1 ],
		[ 0, 0, 1, 0, 1, 0 ]
  	]
	m = 3

	color = [0 for i in range(6)]
 
	print()

	graphColoring(graph, m, 0, color)
print()
print(cnt)