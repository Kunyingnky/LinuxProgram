#include "my.h"
int k=0;
int main()
{
//system 由sh-c 派生子进程
//fork直接派生子进程
//子进程先行
//wait,waitpid
//父进程获得的return值为子进程的进程号

	static int r=9;
	pid_t pid;
	int y=9;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(1);
	}
	else if(pid ==0)
	{
		printf("child:pid=%d,ppid=%d,ret=%d\n",getpid(),getppid(),pid);
		printf("child:&k=%p,&r=%p,&y=%p\n",&k,&r,&y);
		//k=10;
		//r=10;
		//y=10;
		printf("child:k=%d,&r=%d,&y=%d\n",k,r,y);
		exit(100);
	}
	else{
		sleep(2);
		printf("parent:pid=%d,ppid=%d,ret=%d\n",getpid(),getppid(),pid);
		printf("parent:&k=%p,&r=%p,&y=%p\n",&k,&r,&y);
		printf("parent:k=%d,&r=%d,&y=%d\n",k,r,y);
		return 0;
				
	}
}
