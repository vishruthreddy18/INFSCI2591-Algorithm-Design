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
};

void knapsack2();
float bound(node u);

int n = 5, W = 13, maxprofit = 0, cnt = 0;

int p[] = {20, 30, 35, 12, 3};
int w[] = {2, 5, 7, 3, 1};
int pw[] = {10, 6, 5, 4, 3};


int main(){
    knapsack2();

    cout << "Max Profit: " << maxprofit << endl;
    cout << "No. of nodes examined: " << cnt << endl;

    return 0;
}

void knapsack2(){
    queue<node> Q;
    node u, v;
    v.level = v.profit = v.weight = maxprofit = 0;

    Q.push(v);

    while(!Q.empty()){
        cnt++;
        v = Q.front();
        Q.pop();
        u.level = v.level + 1;
        u.weight = v.weight + w[u.level - 1];
        u.profit = v.profit + p[u.level - 1];

        if(u.weight <= W && u.profit > maxprofit){
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

float bound(node u){

    int j, k, totweight;
    float result;

    if(u.weight >= W){
        return 0;
    }
    
    else{
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;

        while(j <= n && totweight + w[j] <= W){

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
}