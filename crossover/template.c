#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAX 10
main()
{
	int x = 1;
	int cnt =0;
	while(x++ <100) {
		cnt++;
		x *=x;
		if (x<10) continue;
		if (x>50) break;
	}
	printf(" %d", cnt);
}
