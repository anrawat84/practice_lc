#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

void reverse(string &s, int beg, int end)
{
	while (beg < end) {
		char tmp = s[beg];
		s[beg] = s[end];
		s[end] = tmp;
		beg++, end--;
	}
}

void reverse_string(string &s)
{
	int len = s.length();
	int l =0, h = len-1;
	while (l < h) {
		char tmp = s[l];
		s[l] = s[h];
		s[h] = tmp;
		l++, h--;
	}
	int beg = 0, end;
	for (int i = 0; i <= len; i++) {
		if (s[i] == ' ' || s[i] == '\0') {
			end = i-1;
			reverse(s, beg, end);
			beg = i+1;
		}
	}
}

int main()
{
	string str = "  My name  is Anoop Rawat";
	reverse_string(str);
	cout << str << endl;
//	int res;
//	printf("\n res = %d", res);
	return 0;
}
