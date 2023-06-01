#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void SearchAlgo(int l, int r, int x, int arr[]);

int main()
{
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the element to be searched: ";
    cin >> x;

    SearchAlgo(0, n-1, x, arr);

    return 0;
}

void SearchAlgo(int l, int r, int x, int arr[])
{
    while(r >= l)
    {
        int m1 = (2 * l + r) / 3;
        int m2 = (2 * r + l) / 3;
        
        if(arr[m1] == x || arr[m2] == x)
        {
            if(arr[m1] == x)
            {
                cout << "Element found at position " << m1;
                return;
            }
            cout << "Element found at position " << m2;
            return;
        }

        if(x < arr[m1])
        {
            SearchAlgo(l, m1 - 1, x, arr);
            return;
        }

        else if(x > arr[m2])
        {
            SearchAlgo(m2 + 1, r, x, arr);
            return;
        }
            
        else
        {
            SearchAlgo(m1 + 1, m2 - 1, x, arr);
            return;
        }
    }
    
    cout << "Element not found";
    return;
}