#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;


#define IS_EVEN(elem) (elem%2 ? 0 : 1)
void arrange_even_odd(int *arr, int n)
{
	int even = 0, odd = 1;
	while (true) {
		cout << "even = " << even << "  " << "odd = " << odd << endl;
		while (even < n && arr[even] % 2 == 0) {
			even +=2;
		}
		while (odd < n && arr[odd]%2 == 1) {
			odd +=2;
		}

		if (even < n && odd < n) {
			cout << "swapping" << endl;
			swap(arr[odd], arr[even]);
		}
		else break;
	}
}

void arrange_even_odd1(int *arr, int n)
{
	int even = 0, odd = 1;
	for (int i =0; i < n; i++) {
		if (i%2 == 0 && (arr[i] %2 == 0)) {
			even +=2;
		} else if (i%2 == 1 &&(arr[i]%2 == 1)) {
			odd +=2;
		} else {
			swap(arr[odd], arr[even]);
		}
	}
}

void printarr(int *arr, int len)
{
	for (int i = 0; i < len; i++) {
		cout << arr[i] <<  "  ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {3, 6, 12, 1, 5 ,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	printarr(arr, len);
	arrange_even_odd(arr, len);
	printarr(arr, len);
//	int res;
//	printf("\n res = %d", res);
	return 0;
}
