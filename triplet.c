#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

//1,2,5,8,10,20
//1,2,3,4,5 6,
int cmp_int(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x-y;
}

int triangular_triplet(int *arr, int len)
{
	qsort(arr, len, sizeof(int), cmp_int);
	for(int i = len-1; i>=2; i--) {
		if (arr[i] > arr[i-1]+arr[i-2]) {
			return 1;
		}
	}
	return 0;
}
int main()
{
//	int arr[] = {10, 2, 5, 1, 8, 20};
	int arr[] = {1,2,3,4,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = triangular_triplet(arr, len);
	printf("\n res = %d", res);
	return 0;
}
