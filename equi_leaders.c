#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
#define MAX 10

using namespace std;

int equi_leaders(vector <int> &v)
{
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		cout<< v[i] << "\t";
	}
	sort(v.begin(), v.end());
	cout << "\n";
	for (auto it: v) {
		cout << it << "\t";
	}
}
int main()
{
	vector <int> v = {4,3,4,4,4,2};
	int res = equi_leaders(v);
	printf("\n res = %d", res);
	return 0;
}
