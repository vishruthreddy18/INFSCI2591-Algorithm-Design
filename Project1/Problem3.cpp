#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <tuple>
#include <string>
#include <time.h>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

tuple<int,int,int> maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0, left, right;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
            left = i;
        }
	}

	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum) {
			right_sum = sum;
            right = i;
        }
	}

    int middle_sum = left_sum + right_sum - arr[m];

    if(middle_sum >= left_sum && middle_sum >= right_sum) {
        return make_tuple(middle_sum, left, right);
    } else if(left_sum > middle_sum && left_sum > right_sum) {
        return make_tuple(left_sum, left, m);
    } else if (right_sum > middle_sum && right_sum > left_sum) {
        return make_tuple(right_sum, m+1, right);
    }

	return make_tuple(INT_MIN, -1, -1);
}

tuple<int, int,int> maxSubArraySum(int arr[], int l, int h)
{
	if (l > h)
		return make_tuple(INT_MIN, -1,-1);
	if (l == h)
		return make_tuple(arr[l], l,l);

	int m = (l + h) / 2;

    tuple<int,int,int> left  = maxSubArraySum(arr, l, m - 1);
    tuple<int,int,int> right = maxSubArraySum(arr, m + 1, h);
    tuple<int,int,int> cross = maxCrossingSum(arr, l, m, h);

    int left_sum = get<0>(left);
    int right_sum = get<0>(right);
    int middle_sum = get<0>(cross);

    int max_sum = max(left_sum, right_sum, middle_sum);

    if (left_sum == max_sum) {
        return make_tuple(left_sum, l, m);
    } else if (right_sum == max_sum) {
        return make_tuple(right_sum, m+1, h);
    } else if (middle_sum == max_sum) {
		return make_tuple(middle_sum, get<1>(cross), get<2>(cross) );
    }
	
	return make_tuple(INT_MIN, -1, -1);
}

int main()
{
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -10, -100, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	// for(int i = 0; i < 100000; i++)
    // {
    //     arr[i] = rand()%100 - 50;
	// 	cout << arr[i] << " ";
    // }
	// cout << "\n";

	for(int i = 0; i < 21; i++)
		cout << arr[i] << " ";
	
	int n = 21;

	//int n = sizeof(arr) / sizeof(arr[0]);

	tuple<int,int,int> max_tup = maxSubArraySum(arr, 0, n - 1);

	printf("\nMaximum Contiguous Sum: %d \nFirst Index %d \nLast Index %d\n", get<0>(max_tup), get<1>(max_tup)+1, get<2>(max_tup)+1);
	clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
	getchar();
	return 0;
}
