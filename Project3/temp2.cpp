#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

void knapsack(int i, int n, int profit, int weight, int W, int maxProfit, vector<int> &p, vector<int> &w, vector<int> &pw, vector<bool> &bestset, vector<bool> &include);
bool promising(int i, int n, int profit, int weight, int W, int maxProfit, vector<int> &p, vector<int> &w, vector<int> &pw, vector<bool> &bestset, vector<bool> &include);

int main()
{
    int n, W, maxProfit = 0;

    cout << "\nEnter the number of items and the threshold weight:\n";
    cin >> n >> W;
    cout << endl;

    vector<int> w;
    vector<int> p;
	vector<int> pw;

    cout << "Enter the prices and weights of the items:\n";

    for(int itr1 = 0; itr1 < n; itr1++)
    {
        int x, y, z;
        cin >> y >> x ;
		z = y / x;
        w.push_back(x);
        p.push_back(y);
		pw.push_back(z);
    }

    vector<bool> bestset(n);
	vector<bool> include(n);

	cout << "\nBestset before\n";
    for(int itr = 0; itr < n; itr++)
        cout << bestset[itr] << " ";

	knapsack(0, n, 0, 0, W, 0, p, w, pw, bestset, include);

	cout << "\nBestset after\n";
	for(int i = 0; i < n; i++)
        cout << include[i] << " ";

	cout << "Max Profit: " << maxProfit << endl;
    
    return 0;
}

void knapsack(int i, int n, int profit, int weight, int W, int maxProfit, vector<int> &p, vector<int> &w, vector<int> &pw, vector<bool> &bestset, vector<bool> &include)
{
	cout << "\nValue of i: " << i;
    if(weight <= W && profit > maxProfit)
    {
        maxProfit = profit;
        bestset[i] = 1;
		include[i] = 1;
		cout << "\nBestset in Knapsack\n";
		for(int q = 0; q < n; q++)
			cout << bestset[q] << " ";
		cout << "\nMaxProfit and weight in Knapsack: " << maxProfit << " " << weight << endl;
    }

    if(promising(i, n, profit, weight, W, maxProfit, p, w, pw, bestset, include))
    {
        bestset[i + 1] = 1;
		cout << "\nBestset in Promising 1\n";
		for(int q = 0; q < n; q++)
			cout << bestset[q] << " ";
		cout << "\nMaxProfit and weight in Promising 1: " << maxProfit << " " << weight << endl;
        knapsack(i + 1, n, profit + p[i + 1], weight + w[i + 1], W, maxProfit, p, w, pw, bestset, include);
        bestset[i + 1] = 0;
		cout << "\nBestset in Promising 2\n";
		for(int q = 0; q < n; q++)
			cout << bestset[q] << " ";
		cout << "\nMaxProfit and weight in Promising 2: " << maxProfit << " " << weight << endl;
        knapsack(i + 1, n, profit, weight, W, maxProfit, p, w, pw, bestset, include);
    }
}

bool promising(int i, int n, int profit, int weight, int W, int maxProfit, vector<int> &p, vector<int> &w, vector<int> &pw, vector<bool> &bestset, vector<bool> &include)
{
	int j = 0, k, totweight;
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

		if(k < n)
			bound  = bound + (W - totweight) * pw[k];
		
		return bound > maxProfit;
	}
}