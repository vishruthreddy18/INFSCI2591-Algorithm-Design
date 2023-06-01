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

void ff(int weight[], int n, int threshold);

int main()
{
	float w[] = {0.1, 0.26, 0.35, 0.4, 0.5, 0.6, 0.75, 0.99};
    int n = 8;
    int weight[n];

    for(int i = 0; i < n; i++)
        weight[i] = w[i] * 100;

	int threshold = 100;
	
	ff(weight, n, threshold);
    cout << endl;
	return 0;
}

void ff(int weight[], int n, int threshold)
{
	int res = 0, bin[n], i = 0;

	while(n--)
    {
		int j = 0;
		while(j < res)
        {
			if (bin[j] >= weight[i])
            {
				bin[j] = bin[j] - weight[i];
				break;
			}
            j++;
		}

		if (j == res)
			bin[res++] = threshold - weight[i];

        i++;
	}

    cout << "Number of bins required: " << res;
}