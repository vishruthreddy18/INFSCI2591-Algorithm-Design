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
        cout << "Vertex " << temp[i] << " has the highest degree of " << m << endl;
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
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    cout << endl;

    cout << "Here,\n";
    for(int i = 0; i < n; i++)
    {
        cout << i << " corresponds to Vertex " << char(i + 65) << "\n";
    }
    cout << "Enter the source and destination vertices of the edges between 0 and " << n - 1 << endl;

    int start, end;
    vector<int> adj[n];
    vector<int> arr(n);

    for(int i = 0; i < e; i++)
    {
        cin >> start >> end;
        arr[start]++;
        arr[end]++;
        addEdge(adj, start, end);
    }

    cout << endl;
    printGraph(adj, n);

    cout << endl;
    countEdges(arr);
}