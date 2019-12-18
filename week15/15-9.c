//多线程边写边读
//第三版本 
//用信号量解决
#include "my.h"
int tickets =100;//共享变量
sem_t empty ,full;

//work0 和 work1交替打印出来
void *worker0(void *arg)
{
	while(1)
	{
		sem_wait(&empty);//p源于
		if(tickets>0)
		{
			printf("worker0 read ticket:%d\n",tickets);
			tickets--;
			sem_post(&full);
		}
		else
		{
			sem_post(&full);
			break;
		}

	}
	return NULL;
}
void *worker1(void *arg)
{	
	while(1)
	{
		sem_wait(&full);//p源于
		if(tickets>0)
		{
			printf("worker1 read ticket:%d\n",tickets);
			tickets--;
			sem_post(&empty);
		}
		else
		{
			sem_post(&empty);
			break;
		}
	}
	return NULL;
}
int main()
{
	pthread_t tid[2];
	int i,ret;
	
	void *(*pt[2])(); //指针数组、、//函数指针数组
	pt[0] = worker0;
	pt[1] = worker1;
	//TODO
	//对全局变量进行初始化
	ret = sem_init(&empty,0,1);
	ret = sem_init(&full,0,0);//同步信号量	
	for(i=0;i<2;i++)
	{
		ret = pthread_create(&tid[i],NULL,pt[i],NULL);
		if(ret!=0)
		{
			perror("create thread!\n");
			exit(1);
		}
	}
	for(i=0;i<2;i++)
		pthread_join(tid[i],NULL);
	return 0;
}
