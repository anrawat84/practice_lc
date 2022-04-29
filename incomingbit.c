#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 10

void checkdivis(int num)
{
	int rem = 0;
	int i = 5;
	while (i--) {
		int bit = 0;
		scanf("%d", &bit);
		if (bit == 1) {
			rem = (rem *2+1)%num;
		} else if (bit == 0) {
			rem = (rem * 2)%num;
		} else {
			printf("\n invalid bit");
			break;
		}	
		if (rem % num == 0) {
			printf("YES");
		} else printf("NO");
	}
}
int main()
{
	checkdivis(3);
	return 0;
}
