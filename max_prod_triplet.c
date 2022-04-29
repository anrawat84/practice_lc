#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

int cmp_int(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x-y;
}

int max_prod_triplet(int *arr, int len)
{
	qsort(arr, len, sizeof(int), cmp_int);
	return (arr[len-1] *arr[len-2] *arr[len-3]);
}
int main()
{
	int arr[] = {-3, 1, 2, -2, 5, 6};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = max_prod_triplet(arr, len);
	printf("\n max = %d", res);
	return 0;
}
