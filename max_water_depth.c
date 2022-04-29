#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX_ARR 10

using namespace std;

#define MAX(a, b) a > b ? a : b

int max_depth(int *arr, int len)
{
	int curr_dp = 0, max_dp = -1;
	int i = 0;
	if (arr[i] < arr[i+1]) {

	}
	for (i; i < len; i++) {
		if (arr[i] > arr[i+1]) {
			curr_dp = arr[i] - arr[i-1];
		}
		max_dp = MAX(curr_dp, max_dp);
	}
	return max_dp;
}
int main()
{
	int arr[] = {1,3,2,1,2,1,5,3,3,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = max_depth(arr, len);
	printf("\n res = %d", res);
	return 0;
}
