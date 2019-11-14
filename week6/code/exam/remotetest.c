#include "/home/rlk/week6/staticlib/staticlib.h"
#include <stdio.h>
int main()
{
	int a[5]={12,0,-454,7668,334};
	showarray(a,5);
	printf("max=%4d\n",max(a,5));
	printf("sum=%4d\n",sum(a,5));
	return 0;
}

