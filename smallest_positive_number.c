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
	return x - y;
}

void printarr(int *arr, int len)
{
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int min_element(int *arr, int len)
{
	int var = 1;

	for (int i = 0; i < len; i++) {
		/*
		if (arr[i] <= 0) {
			continue;
		}
		if (arr[i] != var) {
			if (i > 0 && (arr[i] != arr[i-1])) {
				return var;
			}
		}*/
		if (arr[i] == var) {
			var++;
			continue;
		}
	}
	return var;
}

int main()
{
	int arr[] = {1, 1, 0, -1, -2};
	int len = sizeof(arr)/sizeof(arr[0]);
	qsort(arr, len, sizeof(int), cmp_int);
	printarr(arr, len);
	int res = min_element(arr, len);
	printf("\n res = %d", res);
	return 0;
}
