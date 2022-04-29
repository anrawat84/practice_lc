#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cstring>
#include <climits>
#define MAX 10

using namespace std;

typedef struct uniq_t {
	int val;
	int index;
}uniq;
int find_index(vector <int> &v, int elem)
{
	for (int i = 0; i < v.size(); i++) {
		if (elem == v[i]) {
			return i;
		}
	}
	return 0;
}

int first_unique(vector <int> &v)
{
	int l_index = INT_MAX;
	int sz = v.size();
	int save;
	map<int, int> mp;
	for (auto itr: v) {
		mp[itr]++;
	}
	for (auto itr: mp) {
		if (itr.second == 1) {
			cout << itr.first << "   ";
		}
	}	
	return -1;
}
int main()
{
	vector <int> v = {4, 10, 5, 4, 2, 10};
	//vector <int> v = {6,4,4,6};
	int res = first_unique(v);

	printf("\n res = %d", res);
	return 0;
}
