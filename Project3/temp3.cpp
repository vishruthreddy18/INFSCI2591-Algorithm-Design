#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

bool isomorphic(int n, vector<int> &map);
bool promising(int x, vector<int> &map);

int n1, n2;
vector<vector<int> > graph1, graph2;

int main()
{
    cout << "Enter the number of vertices of graphs 1 and 2:\n";
    cin >> n1 >> n2;

    if(n1 != n2)
    {
        cout << "Graphs are not isomorphic.";
        return 0;
    }

    graph1 = vector<vector<int> > (n1, vector<int>(n1, 0));
    graph2 = vector<vector<int> > (n2, vector<int>(n2, 0));

    int e1, e2;

    cout << "Enter the number of edges:\n";
    cin >> e1 >> e2;

    if(e1 != e2)
    {
        cout << "Graphs are not isomorphic.";
        return 0;
    }

    cout << "Enter the source and destination vertices of G1:\n";

    for(int i = 0; i < e1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph1[x][y] = 1;
        graph1[y][x] = 1;
    }

    cout << "Enter the source and destination vertices of G2:\n";

    for(int i = 0; i < e2; i++)
    {
        int x, y;
        cin >> x >> y;
        graph2[x][y] = 1;
        graph2[y][x] = 1;
    }

    vector<int> map(n1);

    bool temp = isomorphic(0, map);

    if(temp)
    {
        cout << "Graphs are Isomorphic." << endl;
        return 1;
    }
    
    cout << "Graphs are not isomorphic." << endl;

    return 0;
}

bool isomorphic(int x, vector<int> &map)
{
    if(promising(x, map))
    {
        if(x == n1)
        {
            for(int i = 0; i < x; i++)
            {
                cout << map[i] << ' ';
            }
            cout << endl;
            return true;
        }
        for(int i = 0; i < n2; i++)
        {
            int flag = 0;
            for(int j = 0; j < x; j++)
            {
                if(map[j] == i)
                    flag = 1;
            }

            if(flag == 1)
                continue;

            map[x] = i;
            if(isomorphic(x + 1, map))
                return true;
        }

        return false;
    }

    else
        return false;
}

bool promising(int x, vector<int> &map)
{
    for(int i = 0; i < x - 1; i++)
    {
        if(graph1[i][x - 1] != graph2[map[i]][map[x - 1]])
            return false;
    }

    return true;
}