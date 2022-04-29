// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int size)
{
	int *count = new int[sizeof(int)*(size - 2)];
	int i;
		
	cout << " Repeating elements are ";
	for(i = 0; i < size; i++)
	{
		if(count[arr[i]] == 1)
			cout << arr[i] << " ";
		else
			count[arr[i]]++;
	}
	cout << endl;
}

void printRepeatingAbs(int *arr, int len)
{
	cout << endl;
	for (int i = 0; i < len; i++) {
		if (arr[abs(arr[i])] < 0) {
			cout << abs(arr[i]) << "  ";
		} else {
			arr[arr[i]] = -arr[arr[i]];
		}
	}
	cout << endl;
}
// Driver code
int main()
{
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printRepeating(arr, arr_size);
	printRepeatingAbs(arr, arr_size);
	return 0;
}

// This is code is contributed by rathbhupendra

