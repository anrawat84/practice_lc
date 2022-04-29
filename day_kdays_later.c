#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const char *get_day(const char *input, int k)
{
//	k = k%7;
	int len = sizeof(days)/sizeof(days[0]);
	for (int i= 0; i < len; i++) {
		if (!(strcmp(days[i], input))) {
			return days[(i+k)%7];
		}
	}
	return NULL;
}

int main()
{
	char input[20] = "Mondayy";
	int k = 101;
	const char *res = get_day(input, k);
	printf("\n res = %s", res);
	return 0;
}
