#include "my.h"
int arg = 0;
void *foo(void *v)
{
	int n=(int )v,*sum,i;
	arg++;
	sum = (int *)malloc(sizeof(int));
	printf("%d : global arg = %d\n",n,arg);
	for(int i=0;i<arg;i++)
		sum = sum+i;
	int arg;
	arg = n*100;
	printf("%d : local arg = %d,sum = %d\n",n,arg,*sum);
	pthread_exit((void *)sum);
}
int main()
{
	pthread_t tid[NUM];
	int rev[NUM],**pt;
	for(int i=0;i<NUM;i++)
	{
		rev[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
		if(rev[i] != 0)
		{
			perror("thread failed!\n");
			exit -1;
		}
		pthread_join(tid[i],(void **)&pt);
		printf("master %d: arg = %d, sum = %d\n",i,arg,*pt);
	}
}
/*
函数简介
函数pthread_join用来等待一个线程的结束。
函数原型为：
int pthread_join(pthread_t thread, void **value_ptr);
参数：
第一个参数为被等待的线程标识符，第二个参数为一个用户定义的指针，它可以用来存储被等待线程的返回值。
这个函数是一个线程阻塞的函数，调用它的函数将一直等待到被等待的线程结束为止，
当函数返回时，被等待线程的资源被收回。
如果执行成功，将返回0，如果失败则返回一个错误号。
*/

//malloc
//int *pt;整形指针，初始化
//int *pt = (int *)malloc(sizeof(int));
//第二个参数的指针的指针
	//	pthread_join(tid[i],void**pt);
