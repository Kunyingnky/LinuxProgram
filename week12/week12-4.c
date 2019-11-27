#include "my.h"
//pipe匿名
//ls |grep 标准管道
//popen标准管道
//管道上限 256*4KB  下限4KB
//CAT /proc/sys/fs/pipe-max-size
int main()
{
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error.reason:[%s]",strerror(errno));
		return -1;
	}
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"create child error.reason:[%s]",strerror(errno));
		return -2;
	}
	else if(pid==0)
	{
		printf("[child]:pid = %d,ppid = %d\n",getpid(),getppid());
		close(fd[0]);		
		sleep(1000);
		exit(0);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		return 0;
	}

}
