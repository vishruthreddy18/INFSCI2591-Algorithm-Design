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

int partition(vector<int> &arr, int l, int h);
void quicksort(vector<int> &arr, int l, int h);

int cnt = 0;

int main()
{
    vector<int> arr;
    // arr.push_back(4);
    // arr.push_back(3);
    // arr.push_back(5);
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(3);

	// arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(8);

	// arr.push_back(8);
    // arr.push_back(7);
    // arr.push_back(6);
    // arr.push_back(5);
    // arr.push_back(4);
    // arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(1);

	arr.push_back(1);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(5);

	int n = 8;
	cout << "Array before Quick Sort:\n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	quicksort(arr, 0, n - 1);

	cout << "\nArray after Quick Sort:\n";

    for (int i = 0; i < n; i++)
	    cout << arr[i] << " ";
    cout << endl;

	// cout << "Count: " << cnt + 28 << endl;

	return 0;
}

void quicksort(vector<int> &arr, int l, int h)
{
    vector<int> stack(h - l + 1);

	int top = 0;

	stack[top++] = l;
	stack[top] = h;

	while (top >= 0) {
		cnt++;
		h = stack[top--];
		l = stack[top--];

		int p = partition(arr, l, h);

        if (h > p + 1) {
            top++;
			stack[top++] = p + 1;
			stack[top] = h;
		}

		if (l < p - 1) {
            top++;
			stack[top++] = l;
			stack[top] = p - 1;
		}
	}
}

int partition(vector<int> &arr, int l, int h)
{
	int x = arr[h];
	int i = l - 1;

	for (int j = l; j <= h - 1; j++)
    {
		cnt++;
		if (arr[j] <= x)
        {
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
		}
	}

    int temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;

	return i + 1;
}