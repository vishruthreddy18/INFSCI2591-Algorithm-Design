#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>

using namespace std;

void floyd(int n, vector< vector<int> > &W);
void path(int n, int start, int end, vector< vector<int> > &P);

int main()
{
    struct timespec begin, end;
    int n, m, w;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges within 0 and " << n * n - n <<": ";
    cin >> m;

    while(m < 0 || m > n * n - n)
    {
        cout << "Enter the correct value of m: ";
        cin >> m;
    }

    clock_gettime(CLOCK_REALTIME, &begin);
    
    cout << "\n";

    vector<vector<int> > arr(n , vector<int> (n, 0));

    cout << "0 matrix\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    for(int i = 0; i < m; i++)
    {
        int a = rand() % n, b = rand() % n;
        w = rand() % 10;

        while(a == b || arr[a][b] != 0)
        {
            a = rand() % n;
            b = rand() % n;
        }
        arr[a][b] = w + 1;
        //arr[b][a] = w;
    }

    cout << "W matrix\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    floyd(n, arr);

    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    printf("\nTime measured: %.6f seconds.\n", elapsed);

    return 0;
}

void floyd(int n, vector< vector<int> > &W)
{
    int D[n][n];
    vector<vector<int> > P(n , vector<int> (n, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            D[i][j] = W[i][j];
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    cout << "D matrix\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }

    cout << "\nP matrix\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << P[i][j] << " ";
        cout << endl;
    }

    cout << "\n";
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && P[i][j] != 0)
            {
                cout << "Intermediate vertex between (" << i << ", " << j << ") is ";
                path(n, i, j, P);
                cout << "\n";
            }

            else if(P[i][j] == 0 && i != j)
                cout << "No intermediate vertex between (" << i << ", " << j << ")\n";
        }
    }
}

void path(int n, int q, int r, vector< vector<int> > &P)
{
    if(P[q][r] != 0)
    {
        path(n, q, P[q][r], P);
        cout << P[q][r] << " ";
        path(n, P[q][r], r, P);
    }
}