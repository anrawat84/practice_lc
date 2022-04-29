#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

int distinct_elem(int *arr, int len)
{
	int map[100] = {0};
	int cnt = 0;
	for (int i = 0; i< len; i++) {
		map[arr[i]]++;
	}
	for (int i = 0; i<100; i++) {
		if (map[i] > 0) {
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	int arr[] = {2,1,1,2,3,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = distinct_elem(arr, len);
	printf("\n res = %d", res);
	return 0;
}
