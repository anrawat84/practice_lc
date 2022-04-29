#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

#define min(a, b) a < b ? a : b
int num_of_platforms(int *arr, int *dep, int len)
{
	int min_plat = 1, plat = 1;
	for (int i = 0; i < len; i++) {
		plat = 1;
		for (int j = i+1; j< len; j++) {
			if (((arr[i] >= arr[j]) && (arr[i] <= dep[j])) || 
			((arr[j] >= arr[i] && arr[j] <= dep[i]))) {
				plat++;
			}
		}
		min_plat = max(plat, min_plat);
	}
	return min_plat;
}

int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = num_of_platforms(arr, dep, len);
	printf("\n min_plat = %d", res);
	return 0;
}
