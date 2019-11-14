 #include<stdlib.h>/*生成随机数所用的头文件*/
#include <stdio.h>
void initarray(int * a,int n)
{
	int i;
	srand(n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;/*产生100以内的随机数*/
	}
//随机生成随机数组
}
void showarray(int * a,int n){
	int i;
		for(i=0;i<n;i++)
			printf("%4d : %4d\n",i,a[i]);
}
