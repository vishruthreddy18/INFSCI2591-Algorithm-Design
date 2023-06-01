#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>
#include <queue>

using namespace std;

void find_both2(int n, vector<int> &arr);

int main()
{
    // int n = 7;
    // int n = 5;
    int n = 9;

    vector<int> arr;

    // arr.push_back(1);
    // arr.push_back(8);
    // arr.push_back(3);
    // arr.push_back(9);
    // arr.push_back(6);
    // arr.push_back(5);
    // arr.push_back(4);

    // arr.push_back(9);
    // arr.push_back(8);
    // arr.push_back(7);
    // arr.push_back(6);
    // arr.push_back(10);

    arr.push_back(11);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);

    find_both2(n, arr);

    return 0;
}

void find_both2(int n, vector<int> &arr)
{
    int small, large;
    if(arr[0] > arr[1])
    {
        small = arr[1];
        large = arr[0];
    }

    else
    {
        small = arr[0];
        large = arr[1];
    }

    for(int i = 1; i < n - 1; i+=2)
    {
        if(arr[i] < arr[i+1])
        {
            if(arr[i] < small)
                small = arr[i];

            if(arr[i+1] > large)
                large = arr[i+1];
        }

        else
        {
            if(arr[i] > large)
                large = arr[i];

            if(arr[i+1] < small)
                small = arr[i+1];
        }
    }

    cout << "Small: " << small << endl;
    cout << "Large: " << large << endl;
}