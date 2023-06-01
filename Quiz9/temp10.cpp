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

struct node{
    int level;
    int profit;
    int weight;
    vector<int> items;
};

int n = 5, W = 13, maxprofit = 0, cnt = 0;

int p[] = {20, 30, 35, 12, 3};
int w[] = {2, 5, 7, 3, 1};
int pw[] = {10, 6, 5, 4, 3};

float bound(node u){

    int j, k;
    int totweight = 0;
    float result = 0.0;

    if(u.weight < W){
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;

        while(totweight + w[j] <= W && j <= n){
            totweight = totweight + w[j];
            result = result + p[j];
            j++;
        }

        k = j;
        if(k <= n){
            result = result + (W - totweight) * pw[k];
        }

        return result;
    }
    
    return 0; 
}

void knapsack2(){
    queue<node> Q;
    node v;
    v.level = v.profit = v.weight = 0;
    node u;

    Q.push(v);
    v.items.push_back

    while(Q.empty() == false){
        cnt++;
        v = Q.front();
        Q.pop();
        u.level = v.level + 1;
        u.items = v.items;
        u.push_back(item[v.level-1]);
        cout << u;
        u.weight = v.weight + w[u.level - 1];
        u.profit = v.profit + p[u.level - 1];

        if(u.profit > maxprofit && u.weight <= W){
            maxprofit = u.profit;
        }

        if(bound(u) > maxprofit)
            Q.push(u);
        
        u.weight = v.weight;
        u.profit = v.profit;

        if(bound(u) > maxprofit){
            Q.push(u);
        }
    }
}

int main()
{
    knapsack2();
    cout << "Max Profit: " << maxprofit << endl;
    cout << "No. of nodes examined: " << cnt << endl;
    return 0;
}