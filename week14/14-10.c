#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_function(void *arg);

int run_now = 1;	/*用run_now代表共享资源*/
void *thread_function(void *arg)
{
		int print_count2 = 0;
		while(print_count2++<5)
		{
			if(run_now = 2)
			{/*子线程：如果run_now为2 就把它修改为1*/
			printf("function thread is run!\n");
			run_now = 1;
			}
			else{
			printf("function thread is sleep\n");
			sleep(1);
			}
		}
	pthread_exit(NULL);
}
int main(){
	int print_count1=1;
	pthread_t tid;
	if(pthread_create(&tid,NULL,thread_function,NULL)!=0)
	{
		perror("thread createion failed!\n");
		exit(1);
	}
	while(print_count1++<5)
	{
		if(run_now==1){
			printf("main thread is running!\n");
			run_now = 2;
		}else{
			printf("main thread is sleeping!\n");
			sleep(1);
		}
	}
	pthread_join(tid,NULL);
	exit(0);
}


