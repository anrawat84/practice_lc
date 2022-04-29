#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

void printvector(vector <int> v)
{
	cout << endl;
	for (auto itr: v) {
		cout << itr << " ";
	}
	cout << endl;
}
int num_of_rectpens(int *arr, int len, int K)
{
	int maps[10] = {0};
	int max_pens = 0, curr_pens = 0;
	vector <int> v;
	for (int i = 0; i < len; i++) {
		maps[arr[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (maps[i] >= 2) {
			v.push_back(i);
		}
	}
	printvector(v);
	for (int i = 0; i < v.size() -1; i++) {
		int a = v[i];
		for (int j = 1; j <v.size(); j++) {
			int b = v[j];
			if ((a * b) >= K) {
				curr_pens++;
			}
		}
	}
	return curr_pens;
}

int main()
{
//	int arr[] = {1,2,5,1,1,2,3,5,1};
	int arr[] = {2,2,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	int X = 4;
	int res = num_of_rectpens(arr, len, X);
	printf("\n res = %d", res);
	return 0;
}
