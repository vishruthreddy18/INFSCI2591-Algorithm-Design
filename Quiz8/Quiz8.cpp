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
bool promising(int i, vector<int> &col);

bool promising(int i, vector<int> &col)
{
    int k = 1;
    bool s = true;

    while(k < i && s != false)
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
    vector<int> col(n + 1);

    vector<int> prom_children;

    while(m && i != n)
    {
        mprod = mprod * m;
        numnodes = numnodes + mprod * n;

        i++;
        m = 0;
        prom_children.clear();

        for(j = 1; j <= n; j++)
        {
            col[i] = j;
            if(promising(i, col))
            {
                m++;
                int a;
                for(a = 0; a < prom_children.size(); a++)
                {
                    if(prom_children[a] == j)
                        break;
                }
                if(a == prom_children.size())
                    prom_children.push_back(j);
            }
        }

        if(m)
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

    cout << "\nEnter the number of queens: ";
    cin >> n;

    int sum = 0, e;
    cout << endl;

    for(int i = 0; i < 20; i++)
    {
        e = estimate_n_queens(n);
        cout << "Estimate after run " << i + 1 << " is " << e << endl;
        sum = sum + e;
    }

    cout << "\nAverage of all the 20 estimates: " << sum / 20 << endl;

    return 0;
}
