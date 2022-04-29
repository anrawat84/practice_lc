#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

int min_deletions(char *str, int len)
{
	int sx = 0, sy;
	int del = 0;
	for (int i =0; i < len; i++) {
		if (str[i] == 'x') {
			sx++;
		}
	}
	sy = len -sx;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'y') {
			if(sx != 0) {
				sy--;
				del++;
			} else {
				return del;
			}
		} else {
			sx--;
		}
	}
	return del;
}

int main()
{
	char str[] = "yxxxyxy";
	int res = min_deletions(str, strlen(str));
	printf("\n res = %d", res);
	return 0;
}
