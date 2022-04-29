#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;
int stone_wall(int *ht, int len)
{
	int last = 0; 
	int c = 0;
	vector <int> S;
	for (int i = 0; i < len; i++) {
		if (ht[i] > last) {
			last = ht[i];
			c++;
			S.push_back(ht[i]);
		}
		else if (ht[i] < last) {
			int j = S.size() -1;
			while (ht[i] < S[j]) {
				S.pop_back();
				j--;
			}
			if (ht[i] != S[S.size()-1]) {
				c++;
				S.push_back(ht[i]);
			}
			last = ht[i];
		}
	}
	return c;				
}

int main()
{
	int height[] = {8, 8, 5, 7, 9, 8, 7, 4, 8};
	int len = sizeof(height)/sizeof(height[0]);

	int res = stone_wall(height, len);
	printf("\n res = %d", res);
	return 0;
}
