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
	int fd1[2],fd2[2];					//fd[0]读 fd[1]写
	char buf1[30],buf2[30],buf3[30];
	int s1,s2,s3;
	int i,j;
	int num;							//求和
	memset(buf1,0,sizeof(buf1));//初始化对象
	memset(buf2,0,sizeof(buf2));
	memset(buf3,0,sizeof(buf3));
	pipe(fd1);//建立好管道
	printf("parent fork child1!\n");
	pid1=fork();
	if(pid1<0)
	{
		perror("foke pid1 failed!\n");
		return -1;
	}
	else if(pid1==0)	//子进程pid1 运行中
	{
		close(fd1[0]);
		printf("[child %d]\t[parent %d]\n",getpid,getppid());
		//pid1向pipe1中写入0-65535个数字
		num = 0;
		for(i=0;i<65536;i++)
		{
			sprintf(buf1,"%d",i);
			write(fd1[1],buf1,sizeof(buf1));
		}
		close(fd1[1]);
		exit(9);
	}
	else
	{
		pipe(fd2);
		printf("parent fork child2!\n");
		pid2=fork();
		if(pid2<0)
		{
			perror("2:foke failed!\n");
			return -1;
		}
		else if(pid2==0)	//子进程pid2 运行中
		{
			close(fd1[1]);
			close(fd2[0]);
			printf("[child %d]\t[parent %d]\n",getpid,getppid());
			//pid2读出0-65535个数字并显示
			for(i=0;i<65536;i++){
				read(fd1[0],buf2,sizeof(buf2));
				sscanf(buf2,"%d",&i);
				printf("%d\n",i);
				
				//并将数字写入pipe2
				sprintf(buf2,"%d",i);
				write(fd2[1],buf2,sizeof(buf2));
			}
			close(fd1[0]);
			close(fd2[1]);
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
			else if(pid3==0)	//子进程pid3 运行中
			{
				printf("[child %d]\t[parent %d]\n",getpid,getppid());
				close(fd2[1]);
				//pid1向pipe1中写入0-65535个数字
				num = 0;
				for(j=0;j<65536;j++)
				{
					//子进程pid3从pipe2中读出数字并求和
					read(fd2[0],buf3,sizeof(buf3));
					sscanf(buf3,"%d",&j);
					num=num+j;
				}
				close(fd2[0]);//fd[0]读
				printf("the sum of 0-65535 is %ld\n",num);
				exit(99);
			}
			else
			{
				printf("Parent is waiting!\n");
				pid1=wait(&s1);
				pid2=wait(&s2);
				pid3=wait(&s3);
				printf("%d exit code %d\n%d exit code %d\n%d exit code %d\n",pid1,WEXITSTATUS(s1),pid2,WEXITSTATUS(s2),pid3,WEXITSTATUS(s3));
				return 0;
			}
		}
		
	}

}


