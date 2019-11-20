#include "my.h"
int main()
{
	FILE *fp;
	int i;
	if((fp = fopen("out.dat","w+"))==NULL)
	{
		perror("failed to create file\n");
		return -1;
	}
	int pid1,pid2,pid3,status,rv;
	//要求派生3个子进程
	pid1=fork();
	if(pid1<0)
	{
		perror("foke failed!\n");
		return -1;
	}
	else if(pid1==0)
	{
		for(i=0;i<=9;i++)
		{
			fprintf(fp,"1:pid = %d , %d\n",getpid(),i);
		}	
		fprintf(fp,"pid = %d , %d\n",getpid(),i);		
		sleep(3);
		exit(18);
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
			printf("child2 pid=%d\n",getpid());
			for(i=0;i<=9;i++)
			{
				fprintf(fp,"2:pid = %d , %d\n",getpid(),i);
			}	
			sleep(5);
			exit(99);
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
				for(i=0;i<=9;i++)
				{
					fprintf(fp,"3:pid = %d , %d\n",getpid(),i);
				}	
				fprintf(fp,"pid = %d , %d\n",getpid(),i);
				sleep(2);
				exit(108);
			}
			else
			{
				printf("parent waiting child end!\n");
				rv=wait(&status);
				printf("1:child %d end , exit code is %d!\n",rv,WEXITSTATUS(status));
				rv=waitpid(pid1,&status,0);
				printf("2:child %d end , exit code is %d!\n",rv,WEXITSTATUS(status));
				rv=waitpid(pid2,&status,WNOHANG);
				printf("3:child %d end , exit code is %d!\n",rv,WEXITSTATUS(status));
				return 0;
			}
		}
		
	}
//pid_t waitpid(pid_t pid,int * status,int options);

//waitpid等待ID为pid的子进程结束
}
