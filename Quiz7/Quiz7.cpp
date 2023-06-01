#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void printGraph(vector<int> adj[], int V);
void addEdge(vector<int> adj[], int s, int d);
void countEdges(vector<int> arr);

void countEdges(vector<int> arr)
{
    int m = INT_MIN;
    int index;

    vector<int> temp;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];
            index = i;
        }
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == m)
            temp.push_back(i);
    }

    for(int i = 0; i < temp.size(); i++)
        cout << "Node " << char(65 + temp[i]) << " has the highest degree of " << m << endl;
}

void printGraph(vector<int> adj[], int V)
{
    cout << "Adjacency List of the Graph is as follows:" << endl;
    for (int d = 0; d < V; ++d)
    {
        cout << char(65 + d);

        for(int i = 0; i < adj[d].size(); i++)
            cout << " -> " << char(65 + adj[d][i]);

        printf("\n");
    }
}

void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

int main() {

    int n, e;

    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    cout << "\nThe graph has the following nodes:\n";
    for(int i = 0; i < n; i++)
    {
        cout << char(i + 65);
        if(i != n - 1)
            cout << ", ";
    }
    cout << "\n\nEnter the number of edges in the graph: ";
    cin >> e;

    cout << "Enter the source and destination vertices of the edges from A to " << char(65 + n - 1) << endl;

    char start, end;
    vector<int> adj[n];
    vector<int> arr(n);

    for(int i = 0; i < e; i++)
    {
        cin >> start >> end;
        arr[int(start) - 65]++;
        arr[int(end) - 65]++;
        addEdge(adj, int(start) - 65, int(end) - 65);
    }

    cout << endl;
    printGraph(adj, n);

    cout << endl;
    countEdges(arr);
}