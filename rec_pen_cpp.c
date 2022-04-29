#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cstring>
#include <climits>
#define MAX 10
#define MAX_VALUE 1000000000

using namespace std;

void printvector(vector <int> v)
{
	cout << endl;
	for (auto itr: v) {
		cout << itr << " ";
	}
	cout << endl << INT_MAX <<endl;
}


int num_of_rectpens(vector <int> &arr, int K)
{
	int max_pens = 0, curr_pens = 0;
	vector <int> v;
	map <int, int> mp;
	int sz = arr.size();
	if ((sz == 0) || (sz == 1)) {
		return 0;
	}
	for (int i = 0; i < arr.size(); i++) {
		mp[arr[i]]++;
	}
	for (auto itr: mp) {
		if (itr.second/2) {
			v.push_back(itr.first);
			itr.second = itr.second/2;
		}
	}
	if (v.size() == 0) {
		return 0;
	}
	for (int i = 0; i < v.size() -1; i++) {
		int a = v[i];
		for (int j = 1; j <v.size(); j++) {
			int b = v[j];
			if ((a * b) > MAX_VALUE) {
				return -1;
			}
			if ((a * b) >= K) {
				curr_pens++;
			}
		}
	}
	return curr_pens;
}

int main()
{
	vector <int> arr = {2,2,2};
	int X = 4;
	int res = num_of_rectpens(arr, X);
	printf("\n res = %d", res);
	return 0;
}
