#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>

using namespace std;

int miniDist(int distance[], bool Tset[], int n, int e);
void Dijkstra(vector< vector<int> > &graph, int src, int n, int e);

int main()
{
    struct timespec begin, end;
    int n, e, temp;

    cout << "Enter the no. of nodes above 1: ";
    cin >> n;

    while(n < 2)
    {
        cout << "Enter the correct value of nodes: ";
        cin >> n;
    }

    cout << "Enter the no. of edges between 0 and " << n * (n - 1) << ": ";
    cin >> e;

    while(e < 0 || e > n * n - n)
    {
        cout << "Enter the correct value of edges: ";
        cin >> e;
    }

    clock_gettime(CLOCK_REALTIME, &begin);

    temp = e;

    vector<vector<int> > graph(n , vector<int> (n, 0));

    while(temp > 0)
    {
        int a = rand() % n, b = rand() % n;
        int w = rand() % 10;

        while(a == b || graph[a][b] != 0)
        {
            a = rand() % n;
            b = rand() % n;
        }
        graph[a][b] = w;
        //graph[b][a] = w;
        temp--;
    }

    cout << "\nPrinting the graph: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    for(int i = 0; i < n; i++)
        Dijkstra(graph, i, n, e);

    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    printf("Time measured: %.6f seconds.\n", elapsed);

    return 0;                           
}

void Dijkstra(vector< vector<int> > &graph, int src, int n, int e) 
{
    int distance[n];                             
    bool Tset[n];
    
    for(int k = 0; k < n; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;              
    
    for(int k = 0; k < n; k++)                           
    {
        int m = miniDist(distance, Tset, n, e); 
        Tset[m] = true;
        for(int k = 0; k < n; k++)                  
        {
            if(!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    cout << "Vertex\t\tDistance from source vertex " << char(65 + src) << endl;
    for(int k = 0; k < n; k++)                      
    { 
        char str = 65 + k; 
        cout << str << "\t\t\t" << distance[k] << endl;
    }
    cout << "\n";
}

int miniDist(int distance[], bool Tset[], int n, int e)
{
    int i, m = INT_MAX;
              
    for(int k = 0; k < n; k++) 
    {
        if(Tset[k] == false)      
        {
            if(distance[k] <= m)
            {
                i = k;
                m = distance[k];
            }
        }
    }
    return i;
}