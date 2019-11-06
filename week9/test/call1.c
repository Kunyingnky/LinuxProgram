#include "my.h"
int main()
{
	char *vector[]={"test4","123","abc",NULL};
	printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
	execvp("test4",vector);//p表示不需要写绝对路径
	//vector运行参数指针
	printf("After calling");

}
