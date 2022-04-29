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
	return y-x;
}

int carParkingRoof(int *arr, int n, int k)
{
	int min_roof = INT_MAX, curr_roof = 0;
	if (k > n) {
		return -1;
	}
	k = k-1;
	qsort(arr, n, sizeof(int), cmp_int);
	for (int i = 0; i < n-k; i++) {
		curr_roof = arr[i] -arr[i+k];
		min_roof = MIN(curr_roof, min_roof);
	}
	return min_roof+1;
}
// 2,6,7,12
//
int main()
{
	int cars[] = {1,2,3,10};
	int n = 4, k = 5;
	int res = carParkingRoof(cars, n, k);
	printf("\n res = %d", res);
	return 0;
}
