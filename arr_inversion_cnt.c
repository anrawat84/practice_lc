#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

int max_inversions(int *arr, int len)
{
	int curr_inv = 0, max_inv = 0;
	for (int i = 0; i < len-1; i++) {
		int elem = arr[i];
		for (int j = i+1; j < len; j++) {
			if (elem > arr[j]) {
				curr_inv++;
			}
		}
		printf("\n For index = %d, inv = %d", i, curr_inv);
	}
	return curr_inv;
}

int main()
{
	int arr[] = {-1,6,3,4,7,4};
	int len = sizeof(arr)/sizeof(arr[0]);

	int res = max_inversions(arr, len);
	printf("\n res = %d", res);
	return 0;
}
