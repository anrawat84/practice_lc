#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <climits>
#define MAX 10

using namespace std;

#define max(a, b) a > b ? a : b
int largest_sum(vector <int> &arr)
{
	int len = arr.size();
	int max_sum = INT_MIN, n_sum = 0;
	for (int i = 0; i < len; i++) {
		int curr_sum = arr[i];
		for (int j = i+1; j<len; j++) {
			curr_sum += arr[j];
			max_sum = max(max_sum, curr_sum);
		}
	}
	return max_sum;
}

int largest_sum_optimal(vector <int> &arr)
{
	int len = arr.size();
	int curr_sum = 0, max_sum = INT_MIN;
	for (int i = 0; i < len; i++) {
		if (curr_sum + arr[i] >= arr[i]) {
			curr_sum += arr[i];
		} else {
			curr_sum = arr[i];
		}
		if (curr_sum > max_sum) {
			max_sum = curr_sum;
		}
	}
	return max_sum;
}

int main()
{
	vector <int> v = {-2, -3, 4, -1, -2, 1, 5, -3};

	int res;
	res = largest_sum_optimal(v);
	printf("\n res = %d", res);
	return 0;
}
