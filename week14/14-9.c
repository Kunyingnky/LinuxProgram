#include "my.h"
void *foo(void * arg)
{
	printf("thread is tunning!\n");
	return (void*)0;
}

int main()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,foo,NULL);
	if(ret)
	{
	perror("create failed!\n");
	exit(1);
	}
//pthread_join(tid,NULL);结果一定 thread running 一定先行
//分离方式
pthread_detach(tid);//结果随机
sleep(5);
printf("Master done.\n");
	return 0;
}
