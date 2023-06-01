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

// 62, 31, 84, 96, 19, 47

int main()
{
	vector<int> arr1;
	arr1.push_back(62);
	arr1.push_back(31);
	arr1.push_back(84);
	arr1.push_back(96);
	arr1.push_back(19);
	arr1.push_back(47);

	// arr1.push_back(1);
	// arr1.push_back(4);
	// arr1.push_back(1);
	// arr1.push_back(2);
	// arr1.push_back(7);
	// arr1.push_back(5);
	// arr1.push_back(2);

	// arr1.push_back(5);
	// arr1.push_back(2);
	// arr1.push_back(9);
	// arr1.push_back(5);
	// arr1.push_back(2);
	// arr1.push_back(3);
	// arr1.push_back(5);

	int n = arr1.size();

	vector<int> arr2 = arr1;
	vector<int> arr3(n);

	cout << "Original Array: ";
	for(int i = 0; i < arr2.size(); i++)
		cout << arr1[i] << " ";
	cout << endl;

	sort(arr1.begin(), arr1.end());

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr1[i] == arr2[j])
			{
				arr3[j] = i;
				arr2[j] = -1;
				break;
			}
		}
	}

	cout << "Table for the counts: ";
	for(int i = 0; i < arr1.size(); i++)
		cout << arr3[i] << " ";
	cout << endl;
	
	cout << "Sorted Array: ";
	for(int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
	cout << endl;

	return 0;
}