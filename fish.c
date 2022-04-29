#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;
int num_alive_fish(vector <int> &v1, vector <int> &v2)
{
	vector <int> ds;
	int l1 = v1.size();
	int l2 = v2.size();
	int cnt = 0;
	for (int i=0; i <l2; i++) {
		if (v2[i] == 1) ds.push_back(v1[i]);

		else {
			while (!ds.empty()) {
				if (ds.back() > v1[i]) {
					cnt++;
					break;
				}
				else if (ds.back() < v1[i]) {
					ds.pop_back();
					cnt++;
				}
			}
		}
	}
	return l1-cnt;
}

int main()
{
	vector <int> v1 = {4,3,2,1,5};
	vector <int> v2 = {0,1,0,0,0};
	int res = num_alive_fish(v1, v2);
	printf("\n res = %d", res);
	return 0;
}
