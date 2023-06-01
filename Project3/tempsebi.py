def m_coloring(i):
    color = 0
    if i == n:
        if promising(i):
            print(vcolor)
        return False
    else:
        for color in range(1, m+1):
            vcolor[i] = color
            if m_coloring(i+1):
                break
            vcolor[i] = 0
        return False

def promising(i):
    for i in range(n):
        for j in range(i + 1, n):
            if W[i][j] and vcolor[j] == vcolor[i]:
                return False
    return True

n = 5
vcolor = [0 for x in range(n)]
W = [[False, True, True, True, False],
     [True, False, True, False, True],
     [True, True, False, True, True],
     [True, False, True, False, True],
     [False, True, True, True, False]]

m = 3
m_coloring(0)