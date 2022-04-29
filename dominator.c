#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

int cmp_int(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x-y;
}

int find_inx(int *arr, int len, int val)
{
	for (int i = 0; i < len; i++) {
		if (arr[i] == val) {
			return i;
		}
	}
}

void print_arr(int *arr, int len)
{
	for (int i = 0; i< len; i++) {
		printf(" %d", arr[i]);
	}
}

int dominator(int *arr, int len, int dom)
{
	if (len == 0) {
		return -1;
	}
	if (len == 1) {
		return 0;
	}
	int *tmp = (int *)malloc(len *sizeof(int));
	memcpy(tmp, arr, len *sizeof(int));
	qsort(tmp, len, sizeof(int), cmp_int);
	printf("\n len = %d", len);
	int freq = 1;
	print_arr(tmp, len);
	for (int i = 1; i < len; i++) {
		if (tmp[i] == tmp[i-1]) {
			freq++;
		} else freq = 1;
		if (freq > len/2) {
			int inx = find_inx(arr, len, tmp[i]);
			printf("\n elem = %d", tmp[i]);
			return inx;
		}
	}
	return -1;
}

int main()
{
	// -1,2,3,3,3,3,3,4
	// -1,2,3,3,3,3,3,4
	int arr[] = {2,2,2,3,4,3,2,2,3,3,3,3,2,3,-1,3,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int dom = len/2 + 1;
	int res;
	res = dominator(arr, len, dom);
	printf("\n res = %d", res);
	return 0;
}
