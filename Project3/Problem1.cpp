#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
#include <set>
#include <cstdlib>
#include <random>
#include <stdio.h>

using namespace std;

#define V 6

int cnt = 0;

void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[])
{
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

bool graphColoring(bool graph[V][V], int m, int i,
				int color[V])
{
	if (i == V)
	{
		if (isSafe(graph, color))
			printSolution(color);
		return false;
	}

	for (int j = 1; j <= m; j++)
	{
		color[i] = j;

		if (graphColoring(graph, m, i + 1, color))
			break;

		color[i] = 0;
	}

	return false;
}

void printSolution(int color[])
{
	for (int i = 0; i < V; i++)
		cout << " " << color[i];
	cout << "\n";
	cnt++;
}

int main()
{
	bool graph[V][V] = {
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 0 }
	};

	int m = 3;
	
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(graph, m, 0, color))
		// cout << "Solution does not exist";
	
	cout << "Total number of solutions: " << cnt << endl;

	cout << "\n1 corresponds to Red\n";
	cout << "2 corresponds to Blue\n";
	cout << "3 corresponds to Greeen\n";

	return 0;
}