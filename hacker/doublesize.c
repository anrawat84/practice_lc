#include "stdio.h" 
#include "stdlib.h"
#include "string.h"
#define MAX 10


int cmp_long(const void *a, const void *b)
{
	long x = *(long *)a;
	long y = *(long *)b;
	return x-y;
}

long doubleSize(int arr_count, long *arr, long b)
{
	qsort(arr, arr_count, sizeof(long), cmp_long);
	for(int i = 0; i < arr_count; i++) {
		if (arr[i] > b) {
			return b;
		}
		if (arr[i] == b) {
			b *= 2;
		}
	}
	return b;
}

long dsize(long *arr, long cnt, long b)
{
	unordered_set<long> m;
	for (int i = 0; i < cnt; i++) {
		m.insert(arr[i]);
	}
	while (m.find(b) != m.end()) {
		b = b*2;
	}
	return b;
}

is_double_exist(int *arr, int len)
{
	unordered_set <int> st;
	for (int i = 0; i < len; i++) {
		st.insert(arr[i]);
	}
	for (int i =0; i < len; i++) {
		if (st.find(arr[i] *2)) {
			return true;
		}
	}
	return false;
}

int main()
{
	long arr[] = {2,5,4,6,8};
	int arr_count = sizeof(arr)/sizeof(arr[0]);
	long b = 2;
	long res = doubleSize(arr_count, arr, b);
	printf("\n res = %ld", res);
	int arr1[] = {10,2,5,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res1 = is_double_exist(arr1, len);
	if (res1 == 1) {
		cout << " Exists" << endl;
	} else cout << " NOt exists " << endl;
	return 0;
}
