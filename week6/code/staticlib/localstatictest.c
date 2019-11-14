#include "staticlib.h"
#include <stdio.h>
#define Max 100
int main()
{
	int a[Max]={0};
	int num;
	printf("请输入数组长度:\n");
	scanf("%d",&num);
	initarray(a,num);/*初始化随机数组*/
	showarray(a,num);/*显示数组*/
	printf("max=%4d\n",max(a,num));
	printf("sum=%4d\n",sum(a,num));
	return 0;
}

