#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

int validate_token(char *str)
{
	int len = 0;
	int lc =0, dc = 0;
	while (*str) {
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
			lc++;
		} else if (*str >= '0' && *str <= '9') {
			dc++;
		} else {
			printf("\n invalid password");
			return 0;
		}
		str++;
	}
	printf("\n lc = %d, dc = %d", lc, dc);
	if ((lc %2 == 0) && (dc %2 ==1)) {
		return (lc+dc);
	} else {
		return 0;
	}
}
// op = 0, 1, 3, 7, 0
int main()
{
	char str[] = "test 5 a0A pass007 ?xy1";
	char *token = strtok(str, " \n");
	int max_len = 0, len = 0;
	while (token) {
		printf("\n passwd = %s", token);
		len = validate_token(token);
		printf("\n len = %d", len);
		if (len > max_len) {
			max_len = len;
		}

		token = strtok(NULL, " \n");
	}
	if (max_len == 0) {
		max_len = -1;
	}
	printf("\n max_len = %d", max_len);
	return 0;
}
