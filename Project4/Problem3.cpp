// #include <stdio.h>
// #include <iostream>
// #include <limits>
// #include <vector>
// #include <time.h>
// #include <set>
// #include <cstdlib>
// #include <random>
// #include <queue>
// #include <map>

// using namespace std;

// // Function to find the minimum
// // cost path for all the paths
// void findMinRoute(vector<vector<int> > tsp)
// {
// 	int sum = 0;
// 	int counter = 0;
// 	int j = 0, i = 0;
// 	int min = INT_MAX;
// 	map<int, int> visitedRouteList;

// 	// Starting from the 0th indexed
// 	// city i.e., the first city
// 	visitedRouteList[0] = 1;
// 	int route[tsp.size()];

// 	// Traverse the adjacency
// 	// matrix tsp[][]
// 	while (i < tsp.size() && j < tsp[i].size())
// 	{

// 		// Corner of the Matrix
// 		if (counter == tsp[i].size() - 1)
// 		{
// 			break;
// 		}

// 		// If this path is unvisited then
// 		// and if the cost is less then
// 		// update the cost
// 		if (j != i && (visitedRouteList[j] == 0))
// 		{
// 			if (tsp[i][j] < min)
// 			{
// 				min = tsp[i][j];
// 				route[counter] = j + 1;
// 			}
// 		}
// 		j++;

// 		// Check all paths from the
// 		// ith indexed city
// 		if (j == tsp[i].size())
// 		{
// 			sum += min;
// 			min = INT_MAX;
// 			visitedRouteList[route[counter] - 1] = 1;
// 			j = 0;
// 			i = route[counter] - 1;
// 			counter++;
// 		}
// 	}

// 	// Update the ending city in array
// 	// from city which was last visited
// 	i = route[counter - 1] - 1;

// 	for (j = 0; j < tsp.size(); j++)
// 	{

// 		if ((i != j) && tsp[i][j] < min)
// 		{
// 			min = tsp[i][j];
// 			route[counter] = j + 1;
// 		}
// 	}
// 	sum += min;

// 	// Started from the node where
// 	// we finished as well.
// 	cout << ("Minimum Cost is : ");
// 	cout << (sum);
// }

// // Driver Code
// int main()
// {
//     // [[0,60,100,50,90],
//     // [60,0,70,40,30],
//     // [100,70,0,65,55],
//     // [50,40,65,0,110],
//     // [90,30,55,110,0]]

//     vector<vector<int> > tsp = vector<vector<int> > (5, vector<int>(5, 0));

//     // int arr[] = {-1, 10, 15, 20, 10, -1, 35, 25, 15, 35, -1, 30, 20, 25, 30, -1};
//     int arr[] = {-1,60,100,50,90,60,-1,70,40,30,100,70,-1,65,55,50,40,65,-1,110,90,30,55,110,-1};

//     int k = 0;
//     for(int i = 0; i < 5; i++)
//     {
//         for(int j = 0; j < 5; j++)
//         {
//             tsp[i][j] = arr[k++];
//         }
//     }

// 	// Function Call
// 	findMinRoute(tsp);
// }

// // This code is contributed by grand_master.


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
#define V 5

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
	// int graph[][V] = { { 0, 10, 15, 20 },
	// 				{ 10, 0, 35, 25 },
	// 				{ 15, 35, 0, 30 },
	// 				{ 20, 25, 30, 0 } };
    int graph[][V] = {-1,60,100,50,90,60,-1,70,40,30,100,70,-1,65,55,50,40,65,-1,110,90,30,55,110,-1};

	int s = 0;
	cout << travllingSalesmanProblem(graph, s) << endl;
	return 0;
}
