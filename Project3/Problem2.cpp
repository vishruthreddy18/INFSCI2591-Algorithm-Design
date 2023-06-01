#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

int n = 5, W = 9, maxprofit = 0, numbest = 0;
vector<bool> bestset(n);
vector<bool> include(n);

int p[] = {20, 30, 35, 12, 3};
int w[] = {2, 5, 7, 3, 1};
int pw[] = {10, 6, 5, 4, 3};


void knapsack(int i, int profit, int weight);
bool promising(int i, int weight, int profit);

void knapsack(int i, int profit, int weight)
{
    if(weight <= W && profit > maxprofit)
    {
        maxprofit = profit;
        numbest = i;
        bestset = include;
    }

    if(promising(i, weight, profit))
    {
        include[i + 1] = 1;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = 0;
        knapsack(i + 1, profit, weight);
    }
}

bool promising(int i, int weight, int profit)
{
    int j, k, totweight;
    float bound;

    if(weight >= W)
        return false;
    
    else
    {
        j = i + 1;
        bound = profit;
        totweight = weight;

        while(j <= n && totweight + w[j] <= W)
        {
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }

        k = j;
        if(k <= n)
            bound = bound + (W - totweight) * pw[k];
        
        return bound > maxprofit;
    }

}

int main()
{
    knapsack(0, 20, 2);
    cout << "\nMax Profit: " << maxprofit << endl;

    return 0;
}