#include "my.h"

int main()
{
	pid_t p;
	int i;
	int fd[2],rn,wn;//rn wn写进去多少个
	//fd[0] 读	fd[1]写
	char rbuf[30],wbuf[30];//读、写缓冲
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);//建立好管道
	//psize=fcntl(fd[0],?F_GETPIPE_SZ);
	//printf();
	p=fork();
	if(p<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(p==0)
	{
		close(fd[0]);
		sprintf(wbuf,"1");
		/*while(1)
		//{
			/wn=write(fd[1],wbuf,sizeof(wbuf));
			printf("[child] write to pipe %d byte.\n",wn);
			if(wn==-1)//如果写出现错误
			{
				printf("[child] write error.\n");
				break;
			}
		}*/
		for(i=0;i<65534;i++)
		{
		write(fd[1],wbuf,1);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		while(1)
				{
					rn=read(fd[0],rbuf,sizeof(rbuf));
					printf("[parent] read form pipe %d byte.Content of pipe is %s\n",rn,rbuf);
					if(rn==0)//如果写出现错误
					{
						printf("[parent] read error.\n");
						break;
					}
				}
		close(fd[0]);
		return 0;
	}
}
