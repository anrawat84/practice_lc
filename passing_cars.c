#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

int passing_cars(int *arr, int len)
{
	int cnt = 0;
	for (int i = 0; i < len-1; i++) {
		if (arr[i] == 1) {
			continue;
		}
		for (int j = i+1; j< len; j++) {
			if (arr[j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}
int passing_cars_opt(int *arr, int len)
{
	int sE = 0;
	long long int s = 0;
	for (int i =0; i < len; i++) {
		if (arr[i] == 0) sE++;
		if (arr[i] == 1) s +=sE;
	}
	return s;
}

int main()
{
	int arr[] = {0,1,0,0,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	int res = passing_cars(arr, len);
	printf("\n passing cars = %d", res);
	res = passing_cars_opt(arr, len);
	printf("\n passing cars = %d", res);
	return 0;
}
