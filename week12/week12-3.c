//一个父进程创建三个子进程
/*两两子进程之间各有一个管道
p1=pipe1=p2=pipe2=p3
1.0-65535个数字
2.读出0-65535个数字并显示
并将数字写入pipe2
3.子进程从pipe2中读出数字并求和
一个parent 带child1 child2 child3
只要是父子之间要共享的东西一定要在fork之前
管道的建立要在fork 之前*/
#include "my.h"
int main()
{

	int pid1,pid2,pid3;
	//要求派生3个子进程
	int s1,s2,s3;
	pid1=fork();
	printf("parent fork child1!\n");
	if(pid1<0)
	{
		perror("foke failed!\n");
		return -1;
	}
	else if(pid1==0)
	{
		printf("[child %d]\t[parent %d]\n",getpid,getppid());
		exit(9);
	}
	else
	{
		printf("parent fork child2!\n");
		pid2=fork();
		if(pid2<0)
		{
			perror("2:foke failed!\n");
			return -1;
		}
		else if(pid2==0)
		{
			printf("[child %d]\t[parent %d]\n",getpid,getppid());
			exit(19);
		}
		else 
		{
			printf("parent fork child3!\n");
			pid3=fork();
			if(pid3<0)
			{
				perror("3:foke failed!\n");
				return -1;
			}
			else if(pid3==0)
			{
				printf("[child %d]\t[parent %d]\n",getpid,getppid());
				exit(99);
			}
			else
			{
				pid1=wait(&s1);
				pid2=wait(&s2);
				pid3=wait(&s3);
				printf("%d exit code %d\n%d exit code %d\n%d exit code %d\n",pid1,WEXITSTATUS(s1),pid2,WEXITSTATUS(s2),pid3,WEXITSTATUS(s3));
				return 0;
			}
		}
		
	}

}


