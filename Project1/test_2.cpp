#include <iostream>
#include <string>
#include<stdio.h>
#include<unordered_map>
#include <chrono>
#include <limits.h>

using namespace std;
using namespace std::chrono;

void max(int A[], int n)
{
	unordered_map<int, int> bin;
	int end= -1;
	int sum = 0;
	int len = 0; 
	

	for (int i = 0; i < n; i++)
	{
		if(A[i]==0)
		{
			A[i]=-1;
		}
		else
			A[i] =1;
		
	}
		

	for (int i = 0; i < n; i++) 
	{
		sum = sum + A[i];
		if (sum == 0) 
		{
			len = i + 1;
			end = i;
		}

		if (bin.find(sum) != bin.end()) 
		{
			if (len < i - bin[sum]) 
			{
				len= i - bin[sum];
				end = i;
			}
		}
		else 
			bin[sum] = i;
	}

	for (int i = 0; i < n; i++)
	{
		A[i] = (A[i] == -1) ? 0 : 1;
	}
		

    if(len<=0)
    {
        cout<<"\n No balanced Subset\n";
    }
    else
    {
        cout<<"Start index location: "<<end - len + 1<<"\nEnd index location : "<<end;
    }
	
}



int main()
{
    auto start = high_resolution_clock::now();
    int n, i;
    
    cout<<"Enter the length of the array: ";
    cin>>n;
    int A[n];
    cout<<"\nEnter the array elements";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }

	max(A, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout<<"\n Time taken for computation  "<< duration.count()<<" seconds";
	return 0;
}