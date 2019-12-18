//使用条件变量解决
//多线程边写边读
//第四版本 
//使用条件变量解决
//打印结果严格交替必须是01010101
#include "my.h"
int tickets =100;//共享变量
pthread_mutex_t mutex;//互斥信号//条件变脸需要互斥信号来保护
pthread_cond_t q=PTHREAD_COND_INITIALIZER;
//work0 和 work1交替打印出来
void *worker0(void *arg)
{
	pthread_mutex_lock(&mutex);//先去抢mutex		
	while(tickets>0)
	{
		if(tickets%2==0)
		{
			//如果是偶数piao
			usleep(1000);
			printf("worker0 read ticket:%d\n",tickets);
			tickets--;
			pthread_cond_signal(&q);
			//打印并唤醒对方
		}
		else
		{	
			//当前值为奇数
			//阻塞而退出。
			//放掉mutex
			//当前线程在condition q上面阻塞
			pthread_cond_wait(&q,&mutex);//线程阻塞，等待对方来改变他
		}
		//不阻塞而退出
		pthread_mutex_unlock(&mutex);//线程阻塞，等待对方来改变他	
	}	
	return NULL;
}
void *worker1(void *arg)
{
	pthread_mutex_lock(&mutex);//先去抢mutex		
	while(tickets>0)
	{
		if(tickets%2!=0)
		{
			usleep(1000);
			printf("worker1 read ticket:%d\n",tickets);
			tickets--;
			pthread_cond_signal(&q);
			//打印病唤醒对方
		}
		else
		{
			//阻塞而退出。放掉mutex
			pthread_cond_wait(&q,&mutex);//线程阻塞，等待对方来改变他
		}
		//不阻塞而退出
		pthread_mutex_unlock(&mutex);//线程阻塞，等待对方来改变他	
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
