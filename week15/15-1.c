#include "my.h"

//程序原子性
//g++在高级语言里只有一句话
//但是objdump -d >有三句话

pthread_rwlock_t rwlock;		//读写锁

int g=0;	//全局变量

void *fun(void *param)
{
	int i;
	pthread_rwlock_rdlock(&rwlock);
	for(i = 0;i<LOOP;i++)
		g++;
	pthread_rwlock_unlock(&rwlock);//方开锁
	return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int i,ret;
	ret = pthread_rwlock_init(&rwlock,NULL);//初始化锁
	if(ret)
{
	perror("rwlock");
}
	if(ret!=0)
	pthread_rwlock_unlock(&rwlock);
	for(i = 0;i<NUM;i++)
{
ret = pthread_create(&tid[i],NULL,fun,NULL);//派生线程
if(ret!=0)
}

}
