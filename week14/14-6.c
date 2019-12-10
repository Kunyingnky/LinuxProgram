#include "my.h"
void * fun(void *arg)
{
	struct sendval * k = (struct num *)arg;
	int i=0,sum=0;
	for(;i<k->s;i++){
	sum = sum + i;
	}
	printf("worker---%d : pthread_self return %p\t,sum of %d = %d\n",k->n,(void*)pthread_self(),k->s,sum);

	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM],i;
	struct sendval d;
	for(i=0;i<NUM;i++){
		d.n=i;
		d.s=(i+1)*100;
		ret[i] = pthread_create(&tid[i],NULL,fun,(void *)&d);   //第一次派生线程,将i传入线程,强制类型转换
		if(ret[i] != 0)
		{
			perror("create failed!\n");
			return -1;
		}
		pthread_join(tid[i],NULL);
	}	
	/*for(i=0;i<NUM;i++)
		pthread_join(tid[i],NULL);     //结果随机化*/
	printf("Master %d : All Done\n",getpid());
	return 0;
}
//在多线程编程时，一定要注意顺序，否则结果出现唯一性

