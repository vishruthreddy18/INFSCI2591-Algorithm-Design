def promising(x, map):
    for i in range(x - 1):
        if graph2[map[i]][map[x - 1]] != graph1[i][x - 1]:
            return False
    return True

def isomorphic(x, map):
    if not promising(x,map):
        return False
    if x == n1:
        for i in range(n1):
            print(map[i], end = " ")
        print()
        return True
    for i in range(n2):
        flag = 0
        for j in range(x):
            if map[j] == i:
                flag = 1
        if flag == 1:
            continue
        map[x] = i
        if isomorphic(x + 1, map):
            return True
    return False
        

if __name__ == '__main__':
    n1 = 5
    n2 = 5
    if n1 != n2: # Condition valid for standard input
        print("Non isomorphic")
    e1 = 7
    e2 = 7
    if e1 != e2: # Condition valid for standard input
        print("Non isomorphic")
    graph1 = [[0,1,0,1,0],
            [1,0,1,1,1],
            [0,1,0,1,1],
            [1,1,1,0,0],
            [0,1,1,0,0]]

    graph2 = [[0,1,0,1,1],
            [1,0,0,1,0],
            [0,0,0,1,1],
            [1,1,1,0,1],
            [1,0,1,1,0]]

    # graph1 = [
    #     [0, 1, 1, 0, 1, 0],
    #     [1, 0, 1, 0, 0, 1],
    #     [1, 1, 0, 1, 0, 0],
    #     [0, 0, 1, 0, 1, 1],
    #     [1, 0, 0, 1, 0, 1],
    #     [0, 1, 0, 1, 1, 0]
    # ]
    # graph2 = [
    #     [0, 1, 0, 1, 1, 0],
    #     [1, 0, 1, 0, 0, 1],
    #     [0, 1, 0, 1, 1, 0],
    #     [1, 0, 1, 0, 0, 1],
    #     [1, 0, 1, 0, 0, 1],
    #     [0, 1, 0, 1, 1, 0]
    # ]

    # graph1= [[0,1,0,1,1,0,0],[1,0,1,0,1,0,0],[0,1,0,1,0,1,0],[1,0,1,0,0,0,1],[1,1,0,0,0,1,1],[0,0,1,0,1,0,1],[0,0,0,1,1,1,0]]
    # graph2= [[0,1,0,1,0,1,0],[1,0,1,0,1,0,0],[0,1,0,1,0,1,0],[1,0,1,0,0,0,1],[0,1,0,0,0,1,1],[1,0,1,0,1,0,1],[0,0,0,1,1,1,0]]


    map = [0 for i in range(n1)]
    temp = isomorphic(0, map)
    if temp == True:
        print("Isomorphic")
    else:
        print("Not Isomorphic")