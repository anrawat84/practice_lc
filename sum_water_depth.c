/*
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define MAX_ARR 10

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int get_max(int *arr, int start, int end)
{
	int max = arr[start];
	for (int i = start+1; i <= end; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int max_depth(int *arr, int len)
{
	int sum = 0;
	for (int i = 1; i < len-1; i++) {
		int x = get_max(arr, 0, i-1);
		int y = get_max(arr, i+1, len-1);
		printf("\n max_left = %d, max_right = %d", x , y);
		int minv = min(x, y);
		if ((minv -arr[i]) < 0) continue;
		sum = sum + minv -arr[i];
	}
	return sum;
}

void printarr(int *arr, int len)
{
	printf("\n\n");
	for (int i = 0; i < len; i++) {
		printf(" %d", arr[i]);
	}
}

int max_depth_optimal(int *arr, int len)
{
	int left[len];
	int right[len];
	left[0] = 0;
	int l_max = arr[0];
	int w_level = 0;
	// 4, 2, 0, 3, 2, 5
// left[i] 0, 4, 4, 4, 4, 4
// right[i]5, 5, 5, 5, 5, 0 

	for (int i = 1; i < len; i++) {
		left[i] = l_max;
		l_max = max(arr[i], l_max);
	}
	right[len-1] = 0;
	int r_max = arr[len-1];
	for (int i = len-2; i>=0; i--) {
		right[i] = r_max;
		r_max = max(arr[i], r_max);
	}
	printarr(left, len);
	printarr(right, len);
	for (int i = 1; i < len-1; i++) {
		if ((arr[i] < left[i]) && (arr[i] < right[i])) {
			w_level += (min(left[i], right[i])) - arr[i];
		}
	}
	return w_level;
}

int max_water_level(int *arr, int len)
{
	int left[len];
	int right[len];
	left[0] = 0;
	int l_max = arr[0];
	int max_level = 0;
	int curr_level = 0;
	if (len <= 2) {
		return 0;
	}
	for (int i = 1; i < len; i++) {
		left[i] = l_max;
		l_max = max(arr[i], l_max);
	}
	right[len-1] = 0;
	int r_max = arr[len-1];
	for (int i = len-2; i>=0; i--) {
		right[i] = r_max;
		r_max = max(arr[i], r_max);
	}
	for (int i = 1; i < len-1; i++) {
		if ((arr[i] < left[i]) && (arr[i] < right[i])) {
			curr_level = (min(left[i], right[i])) - arr[i];
			max_level = max(curr_level, max_level);
		}
	}
	return max_level;
}
int main()
{
//	int arr[] = {4,2,0,3,2,5};
//	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
//	int arr[] = {1,3,2,1,2,1,5,3,4,2};
	int arr[] = {5, 8};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = max_depth(arr, len);
	printf("\n res = %d", res);
	res = max_depth_optimal(arr, len);
	printf("\n res = %d", res);
	res = max_water_level(arr, len);
	printf("\n max_water_level = %d", res);
	return 0;
}
