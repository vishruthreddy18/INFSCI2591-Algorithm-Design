#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

void largestSquare(int r, int c, vector< vector<int> > &arr);

int main()
{
    int r = 6, c = 6;
    // cout << "Enter the size of the matrix.\n";
    // cout << "Enter the row value: ";
    // cin >> r;
    // cout << "Enter the column value: ";
    // cin >> c;

    vector<vector<int> > arr(r , vector<int> (c, 0));
    // vector<vector<int> > arr = {  {1, 0, 1, 0, 0},
    //                                 {1, 0, 1, 1, 1},
    //                                 {1, 1, 1, 1, 0},
    //                                 {1, 1, 0, 1, 0},
    //                              };

    // vector<vector<int> > arr = {  { 1, 1, 1, 1, 1, 1}, 
    //                                {1, 1, 1, 1, 0, 0},
    //                                 {1, 1, 1, 1, 1, 1},
    //                                 {1, 1, 1, 0, 0, 0},
    //                                 {1, 0, 1, 0, 1, 1},
    //                                 {0, 0, 1, 1, 1, 1 }
    //                                 };

    // for(int i = 0; i < r; i++)
    // {
    //     for(int j = 0; j < c; j++)
    //         arr[i][j] = rand() & 1 | rand() & 1;
    //         //arr[i][j] = rand() % 2;
    // }

    // int x[20] = {1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0};
    int x[36] = {1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 0, 0,
                1, 1, 1, 1, 1, 1,
                1, 1, 1, 0, 0, 0,
                1, 0, 1, 0, 1, 1,
                0, 0, 1, 1, 1, 1};
    int k = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            arr[i][j] = x[k++];
        }
    }

    cout << "\nBinary matrix\n";

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    largestSquare(r, c, arr);

    return 0;
}

void largestSquare(int r, int c, vector< vector<int> > &arr)
{
    vector<vector<int> > temp(r , vector<int> (c, 0));
    temp = arr;

    for(int i = 1; i < r; i++) 
    { 
        for(int j = 1; j < c; j++) 
        { 
            if(arr[i][j] == 0)
                temp[i][j] = 0;
            else
            {
                // if(arr[i][j-1] < arr[i-1][j] && arr[i][j-1] < arr[i-1][j-1])
                //     temp[i][j] = arr[i][j-1] + 1;
                // else if(arr[i-1][j] < arr[i][j-1] && arr[i-1][j] < arr[i-1][j-1])
                //     temp[i][j] = arr[i-1][j] + 1;
                // else
                //     temp[i][j] = arr[i-1][j-1] + 1;
                temp[i][j] = min(temp[i][j-1], min(temp[i-1][j], temp[i-1][j-1])) + 1;
            }
        } 
    }

    cout << "Temp matrix\n";

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cout << temp[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    int m = INT_MIN;

    // cout << "Max value before: " << m << "\n";

    for(int i = 0; i < r; i++) 
    { 
        for(int j = 0; j < c; j++) 
        { 
            if(m < temp[i][j]) 
                m = temp[i][j]; 
        }             
    }

    // cout << "Max value after: " << m << "\n";

    cout << "Square Size = " << m;
    cout << " Indices are ";
    for(int i = 0; i < r; i++) 
    { 
        for(int j = 0; j < c; j++)
        {
            if(m == temp[i][j])
                cout << "[" << i - m + 2 << ", " << j - m + 2 << "] ";
        }
    }
    
    cout << endl;
}