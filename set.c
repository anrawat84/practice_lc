#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <cstring>
#define MAX 10

using namespace std;

void print_unique_string(const char **ptr, int len)
{
	multiset <string, greater<string>> st;
	for (int i = 0; i < len; i++) {
		char arr[10];
		strcpy(arr, ptr[i]);
		st.insert(arr);
	}
	for (auto itr: st) {
		cout << itr << endl;
	}
}

int main()
{
	const char *ptr[5] = {{"India"}, {"is"}, {"great"}, {"India"}, {"great"}};
//	char ptr[5][10] = {{"India"}, {"is"}, {"great"}, {"india"}, {"great"}}; 
	int len = sizeof(ptr)/sizeof(ptr[0]);
	print_unique_string(ptr, len);
	//printf("\n res = %d", res);
	return 0;
}
