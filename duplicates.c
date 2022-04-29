#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

void repeating(int *arr, int len)
{
	int hash[len] = {0};
	for (int i = 0; i < len; i++) {
		hash[arr[i]]++;
	}
	for (int i = 0; i < len; i++) {
		if (hash[i] >= 2) {
			cout << i << "  " << endl;
		}
	}
}

int main()
{
	int arr[] = {4, 2, 4, 5, 2, 3, 1, 1, 1};
	int len = sizeof(arr)/sizeof(arr[0]);
	repeating(arr, len);
	//printf("\n res = %d", res);
	return 0;
}
