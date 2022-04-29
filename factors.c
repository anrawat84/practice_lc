#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 10

using namespace std;

int factors(int num)
{
	int i = 1;
	int cnt = 0;
	for (int i = 1; i <= sqrt(num); i++) {
		if (num %(i) == 0) {
			if (i == num/i) {
				cout << i << "\t";
				cnt += 1;
				continue;
			}
			cout << i << "\t" << num/i << "\t";
			cnt +=2;
		}
	}
	return cnt;
}

int main()
{
	int num = 100;
	int res = factors(num);
	printf("\n res = %d", res);
	/*
	int res;
	printf("\n res = %d", res);
	*/
	return 0;
}
