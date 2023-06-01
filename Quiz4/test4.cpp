#include <stdio.h>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n, m, w;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges within " << n - 1 << " and " << n * (n - 1) / 2 <<": ";
    cin >> m;

    while(m < n - 1 || m > n * (n - 1) / 2)
    {
        cout << "Enter the correct value of m: ";
        cin >> m;
    }

    // Start of Generate Algorithm
    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a = rand() % n, b = rand() % n;
        w = rand() % 100 + 1;

        while(a == b || arr[a][b] != 0)
        {
            a = rand() % n;
            b = rand() % n;
        }
        arr[a][b] = w;
        arr[b][a] = w;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    // End of Generate Algorithm


    // Start of Properties Algorithm
    // Node number with the largest number of links
    int counter1 = 0, maxnooflinks = INT_MIN, mnl;
    int lnl[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] != 0)
                counter1++;
            else
                continue;
        }
        lnl[i] = counter1;
    }

    for(int i = 0; i < n; i++)
    {
        if(lnl[i] > maxnooflinks)
        {
            maxnooflinks = lnl[i];
            mnl = i;
        }
    }

    // Node with the largest sum of the link weights
    int counter2 = 0, lsumoflinkwts = INT_MIN;
    int lslw[n], sum1 = 0, ls;

    for(int i = 0; i < n; i++)
    {
        sum1 = 0;
        for(int j = 0; j < n; j++)
            sum1 = sum1 + arr[i][j];

        lslw[i] = sum1;
    }

    for(int i = 0; i < n; i++)
    {
        if(lslw[i] > lsumoflinkwts)
        {
            lsumoflinkwts = lslw[i];
            ls = i;
        }
    }

    // Node with the smallest sum of the link weights
    int counter3 = 0, ssumoflinkwts = INT_MAX;
    int sslw[n], sum2 = 0, ss;

    for(int i = 0; i < n; i++)
    {
        sum2 = 0;
        for(int j = 0; j < n; j++)
            sum2 = sum2 + arr[i][j];

        if(sum2 == 0)
            sum2 = INT_MAX;

        sslw[i] = sum2;
    }

    for(int i = 0; i < n; i++)
    {
        if(sslw[i] < ssumoflinkwts)
        {
            ssumoflinkwts = sslw[i];
            ss = i;
        }
    }

    // The link with the smallest weight

    int sw = INT_MAX, swn1, swn2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
                continue;
            else
            {
                if(arr[i][j] < sw)
                {
                    sw = arr[i][j];
                    swn1 = i;
                    swn2 = j;
                }
            }
        }
    }

    cout << "Smallest edge weight is in between the nodes " << swn1 << " and " << swn2 << "\n";
    cout << "Node with the largest number of links: " << mnl << "\n";
    cout << "Node with the smallest sum of link weights: " << ss << "\n";
    cout << "Node with the largest sum of link weights: " << ls << "\n";
    // End of Properties Algorithm

    return 0;
}