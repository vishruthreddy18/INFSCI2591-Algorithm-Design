def hamiltonian(i):
    if(promising(i)):
        global exist
        if(i != n - 1):
            for j in range(1, n):
                vindex[i+1] = j
                hamiltonian(i+1)
        else:
            global flag
            if (flag):
              print(vindex)
              flag = False
              exist = True

def promising(i):
    if((i == n-1 and not W[vindex[n-1]][vindex[0]]) or (i > 0 and not W[vindex[i-1]][vindex[i]])):
        return False
    else:
        j = 0
        while(j < i):
            if(vindex[i] == vindex[j]):
                return False
            j = j+1
        return True
    
# W = [[0,1,0,0,1,0,0,0,0,0,0,0],
#     [1,0,0,0,0,0,1,1,0,0,0,0],
#     [0,1,0,1,0,0,0,1,0,0,0,0],
#     [0,0,1,0,0,0,0,0,1,0,0,0],
#     [1,0,0,0,0,1,0,0,0,1,0,0],
#     [0,0,0,0,1,0,1,0,0,0,1,0],
#     [0,1,0,0,0,1,0,1,0,0,0,0],
#     [0,1,1,0,0,0,1,0,1,0,0,0],
#     [0,0,0,0,0,0,0,1,0,0,0,1],
#     [0,0,0,0,1,0,0,0,0,0,1,0],
#     [0,0,0,0,0,1,0,0,0,1,0,1],
#     [0,0,0,0,0,0,0,0,1,0,1,0]]

W = [[0,1,1,1],
    [1,0,1,1],
    [1,1,0,1],
    [1,1,1,0]]
exist = False
flag = True
n = len(W)
vindex = [None for x in range(n)]
vindex[0] = 0
hamiltonian(vindex[0])
if not exist:
  print("There is no Hamiltonian Cycle in the graph")