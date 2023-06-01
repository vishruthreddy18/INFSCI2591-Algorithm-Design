#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

int estimate_n_queens(int n);
bool promising(int i, int col[]);

bool promising(int i, int col[])
{
    int k = 1;
    bool s = true;

    while(k < i && s)
    {
        if(col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            s = false;
        k++;
    }

    return s;
}

int estimate_n_queens(int n)
{
    int i = 0, numnodes = 1, m = 1, mprod = 1, j;
    // vector<int> col(n);
    int col[n];

    vector<int> prom_children;

    while(m && i != n)
    {
        mprod = mprod * m;
        numnodes = numnodes + mprod * m;

        i++;
        m = 0;
        prom_children.clear();

        for(j = 1; j <= n; j++)
        {
            col[i] = j;
            if(promising(i, col))
            {
                m++;
                prom_children.push_back(j);
            }
        }

        if(m != 0)
        {
            int x = rand() % prom_children.size();
            j = prom_children[x];
            col[i] = j;
        }
    }

    return numnodes;
}

int main()
{
    int n;

    cout << "Enter the number of queens: ";
    cin >> n;

    int sum = 0, e;
    for(int i = 0; i < 20; i++)
    {
        e = estimate_n_queens(n);
        cout << e << endl;
        sum = sum + e;
    }

    cout << "Average: " << sum / 20 << endl;

    return 0;
}