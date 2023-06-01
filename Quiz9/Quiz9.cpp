#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

// #define n 4
#define n 12

bool temp = false;

bool promising(int i, bool W[n][n], int vindex[n]);
void hamiltonian(int i, bool W[n][n], int vindex[n]);

bool promising(int i, bool W[n][n], int vindex[n])
{
    int j;
    bool s;

    if((i == n - 1 && !W[vindex[n - 1]][vindex[0]]) || (i > 0 && !W[vindex[i - 1]][vindex[i]]))
        s = false;
    
    else
    {
        s = true;
        j = 1;

        while(j < i && s)
        {
            if(vindex[i] == vindex[j])
                s = false;
            
            j++;
        }
    }

    // cout << s << " " << i << endl;

    return s;
}

void hamiltonian(int i, bool W[n][n], int vindex[n])
{
    if(promising(i, W, vindex))
    {
        if(i == n - 1)
        {
            // cout << i;
            for(int k = 0; k < n; k++)
                cout << vindex[k] << " ";
            
            cout << endl;
            temp = true;
        }

        else
        {
            for(int j = 1; j < n; j++)
            {
                vindex[i + 1] = j;
                hamiltonian(i + 1, W, vindex);
            }
        }
    }
}

int main()
{
	bool W[n][n] = {
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
	};

    // bool W[n][n] =
    // {
    //     {0, 1, 1, 1},
    //     {1, 0, 1, 1},
    //     {1, 1, 0, 1},
    //     {1, 1, 1, 0}
    // };

    int vindex[n];
    vindex[0] = 0;

    cout << endl;
    hamiltonian(0, W, vindex);

    if(!temp)
        cout << "There is no Hamiltonian Cycle in the graph" << endl;

    return 0;
}