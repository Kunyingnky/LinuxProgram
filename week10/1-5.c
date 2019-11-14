#include "my.h"
int g=10;
int main()
{
	int l=20;
	int status;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if (pid==0)
	{
	 	//int p=99;
		printf("--------------address of var---------------\n");
		printf("child pid=%d\n&g=%16p\n&l=%16p\n&s=%16p\n",getpid(),&g,&l,&s);
		g=100;
		l=200;
		s=300;
		//p=9999;
		execl("./test","test",NULL);
		printf("value in child\n");
		printf("g=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;
		//exit(119);
		//_exit(0);
		//16 64为系统 16进制表示
	}
	else{
		//wait(&status);
		//printf("exit code from child is %d\n",WEXITSTATUS(status));
		printf("--------------address of var in parent---------------\n");
		printf("parent:\n&g=%16p\n&l=%16p\n&s=%16p\n",&g,&l,&s);
		printf("value in parent\n");
		printf("parent:\ng=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;
		//exit(0);
		//_exit(0);
		//%16 64为系统 16进制表示
	}
//虽然没有用wait让父进程等待子进程
//g是全局变量，s是局部变量
//stack smashing de
//return 把栈给释放了,对变量的修改，父进程看不见
//所以改动不能用return
//用_exit紫荆城修改父进程可以看见
}
