#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
using namespace std;

void MaxBinLen(vector <int> arr, int n);

int main()
{
    int n, temp;

	cout << "Enter the size of the binary array: ";
	cin >> n;

	vector <int> arr(n);
    
	cout << "Enter the elements of the binary array: ";

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	MaxBinLen(arr, n);
	return 0;
}

void MaxBinLen(vector <int> arr, int n)
{
	int sum = 0, len = 0, end = -1;
	unordered_map <int, int> hashmap;

	for (int i = 0; i < n; i++)
	{
		if(arr[i] == 0)
			arr[i] = -1;
	}
		
	for (int i = 0; i < n; i++) 
	{
		sum = sum + arr[i];
		if (sum == 0) 
		{
			len = i + 1;
			end = i;
		}

		if (hashmap.find(sum) == hashmap.end())
			hashmap[sum] = i;
		
		else
		{
			if (len < i - hashmap[sum]) 
			{
				end = i;
				len = i - hashmap[sum];
			}
		}
	}	

    if(len > 0)
		cout << "First Index: " << end - len + 1 << "\nLast Index: " << end << endl;
        
    else
        cout << "No balanced Subset\n";
}
