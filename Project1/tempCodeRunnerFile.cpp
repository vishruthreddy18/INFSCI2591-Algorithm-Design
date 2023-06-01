// A Divide and Conquer based program for maximum subarray
// sum problem
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <tuple>
#include <string>

using namespace std;

// A utility function to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// A utility function to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }

// Find the maximum possible sum in arr[] such that arr[m]
// is part of it
tuple<int,int,int> maxCrossingSum(int arr[], int l, int m, int h)
{
	// Include elements on left of mid.
	int sum = 0, left, right;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
            left = i;
        }
	}

	// Include elements on right of mid
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum) {
			right_sum = sum;
            right = i;
        }
	}

	// Return sum of elements on left and right of mid
	// returning only left_sum + right_sum will fail for
	// [-2, 1]
	// return max(left_sum + right_sum - arr[m], left_sum, right_sum);

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

// Returns sum of maximum sum subarray in aa[l..h]
tuple<int, int,int> maxSubArraySum(int arr[], int l, int h)
{
	//Invalid Range: low is greater than high
	if (l > h)
		return make_tuple(INT_MIN, -1,-1);
	// Base Case: Only one element
	if (l == h)
		return make_tuple(arr[l], l,l);

	// Find middle point
	int m = (l + h) / 2;

	/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray
	crosses the midpoint */
    tuple<int,int,int> left  = maxSubArraySum(arr, l, m - 1);
    tuple<int,int,int> right = maxSubArraySum(arr, m + 1, h);
    tuple<int,int,int> cross = maxCrossingSum(arr, l, m, h);

    int left_sum = get<0>(left); // left[0]
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

/*Driver program to test maxSubArraySum*/
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, -10, -100, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
    //maxSubArraySum(arr, 0, n - 1);
	tuple<int,int,int> max_tup = maxSubArraySum(arr, 0, n - 1);

	printf("Maximum contiguous sum is %d, b/n %d and %d\n", get<0>(max_tup), get<1>(max_tup)+1, get<2>(max_tup)+1);
	getchar();
	return 0;
}
