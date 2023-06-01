def ff(bin, n, c):
    res = 0
    j = 0
    rem = [0] * n

    i = 0
    while(n):
        j = 0

        while(j < res):
            if (rem[j] >= bin[i]):
                rem[j] = rem[j] - bin[i]
                break
            j = j + 1

        if (j == res):
            rem[res] = c - bin[i]
            res= res + 1
        
        n = n - 1
        i = i + 1
    
    print("Number of bins required:", res)

if __name__ == "__main__":
    bin = [0.1, 0.26, 0.35, 0.4, 0.5, 0.6, 0.75, 0.99]
    n = len(bin)
    c = 1
    ff(bin, n, c)