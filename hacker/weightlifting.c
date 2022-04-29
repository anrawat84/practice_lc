#include "stdio.h" 
#include "stdlib.h"
#include "string.h"
#include "limits.h"

#define MAX 10
#define MIN(a, b) a < b ? a : b

int cmp_int(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x-y;
}

int weightCapacity(int *arr, int len, int maxcap)
{
	int curr_max = 0, prev_max;
	qsort(arr, len, sizeof(int), cmp_int);
	int l = 0, r = len-1;
	while (l < r) {
		int curr_max = arr[l] + arr[r];
		if (curr_max > maxcap) {
			r--;
		} else if (curr_max < maxcap) {
			prev_max = curr_max;
			l++;
		} else if (curr_max = maxcap) {
			return curr_max;
		}
	}
	return prev_max;
}

//4,5,8,9
int main()
{
	int weights[] = {4,8,5,9};
	int w_count = sizeof(weights)/sizeof(weights[0]);
	int maxcap = 20;
	int res = weightCapacity(weights, w_count, maxcap);
	printf("\n res = %d", res);
	return 0;
}
