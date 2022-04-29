#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

#define min(a, b) a < b ? a : b
int min_avg_slice(int *arr, int len)
{
	int curr_min, min;
	float curr_avg, min_avg = 100.0;
	int l_index;

	for (int i = 0; i < len-1; i++) {
		int curr_sum = arr[i];
		for (int j = i+1; j<len; j++) {
			curr_sum += arr[j];
			curr_avg = (float)curr_sum/(j-i+1);
			if (curr_avg < min_avg) {
				min_avg = curr_avg;
				l_index = i;
			}
		}
		printf("\n For i = %d, min_avg = %f, l_index = %d", i, min_avg, l_index);
	}
	return l_index;
}

int min_avg_slice_opt(int *arr, int len)
{
	float mn = 100;
	int mi = 0;
	for (int i =0; i < len -2; i++) {
		float v1 = (float)(arr[i] + arr[i+1] + arr[i+2])/3;
		float v2 = (float)(arr[i] + arr[i+1])/2;
		if (mn > v1 || mn > v2) {
			mn = min(v1, v2);
			mi = i;
		}
	}
	if (mn > (arr[len-1] + arr[len-2])/2) {
		return (len-2);
	}
	return mi;
}

int main()
{
	int arr[] = {4,7,2,2,1,5,1,1,15,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = min_avg_slice(arr, len);
	printf("\n %d\n", res);
	res = min_avg_slice_opt(arr, len);
	printf("\n %d\n", res);
	return 0;
}
