#include <iostream>
#include <stack>
#include <cstring>
#define MAX 10

using namespace std;
int is_matching_brackets(const char *s, int len)
{
	stack<char> st;
	int i = 0;
	int err = 0;
	while (s[i] != '\0') {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			st.push(s[i]);
			i++;
			continue;
		}
		char ch = st.top();
		printf("\n ch = %c	s[i] = %c", ch, s[i]);
		printf("\n\n bef switch");
		switch (ch) {
			printf("\n in switch");
			case '(':
				if (s[i] != ')') {
					err = -1;
					goto end;
				}
				break;
			case '{':	
				if (s[i] != '}') {
					err = -1;
					goto end;
				}
				break;
			case '[':	
				if (s[i] != ']') {
					err = -1;
					goto end;
				}
				break;
			default:
				err = -1;
				goto end;
		}
		st.pop();
		i++;
	}
end:
	return err;
}
int main()
{
	const char *s = "{[()()]}";
	int len = strlen(s);
	int res = is_matching_brackets(s, len);
	printf("\n res = %d", res);
	return 0;
}
