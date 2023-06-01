#include <iostream>
#include <time.h>
#include <limits.h>
#include <vector>
using namespace std;

void OptimalOrder(int i, int j, vector< vector<int> > &m);
int MinMult(int d[], int n);

int main()
{
    struct timespec begin, end; 
    
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int arr[++n];
 
    cout << "Enter the dimensions of the " << n << " matrices: \n";
 
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    clock_gettime(CLOCK_REALTIME, &begin);

    //cout << "Minimum number of multiplications is ";
    MinMult(arr, n);

    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    
    printf("\nTime measured: %.6f seconds.\n", elapsed);
 
    return 0;
}

int MinMult(int d[], int n)
{
    
    vector< vector<int> > m(n,vector<int>(n, 0));

    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    int j, q;
     

    for (int diagonal = 2; diagonal < n; diagonal++)
    {
        for (int i = 1; i < n - diagonal + 1; i++)
        {
            j = i + diagonal - 1;
            m[i][j] = 2147483647;
 
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    m[j][i] = k;
                }
            }
        }
    }

    // for(int l = 0; l < n; l++)
    // {
    //     for(int x = 0; x < n; x++)
    //     {
    //         cout << m[l][x] << " ";
    //     }
    //     cout << endl;
    // }

    OptimalOrder(1, n - 1, m);
    return 0;
}

void OptimalOrder(int i, int j, vector< vector<int> > &m)
{
    int k;
    if(i == j)
    {
        cout << "A" << i;
        //return;
    }

    else
    {
        k = m[j][i];
        cout << "(";
        OptimalOrder(i, k, m);
        OptimalOrder(k + 1, j, m);
        cout << ")";
        //return;
    }
}