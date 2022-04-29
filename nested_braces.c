#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10


int properly_nested(const char *str, int len)
{
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			cnt++;
		} else if (str[i] == ')') {
			if (cnt > 0) {
				cnt--;
			} else {
				return 0;
			}
		}
	}
	return ((cnt == 0) ? 1 : 0);
}
int main()
{
	const char *str = "(()(())()";
	int res = properly_nested(str, strlen(str));
	printf("\n res = %d", res);
	return 0;
}
