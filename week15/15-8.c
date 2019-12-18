//多线程边写边读
//第二版本 
//迭代，增加一个互斥变量
//打印结果没有1
#include "my.h"
int tickets =100;//共享变量
pthread_mutex_t mutex;//互斥信号
//work0 和 work1交替打印出来
void *worker0(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(tickets>0)
		{
			printf("worker0 read ticket:%d\n",tickets--);
			pthread_mutex_unlock(&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_yield();//让权
	}
	return NULL;
}
void *worker1(void *arg)
{	
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(tickets>0)
		{
			printf("worker1 read ticket:%d\n",tickets--);
			pthread_mutex_unlock(&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_yield();//让权
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
	pthread_mutex_init(&mutex,NULL);
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
