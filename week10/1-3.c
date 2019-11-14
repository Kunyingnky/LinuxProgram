#include "my.h"

static void callback1()
{
	printf("--------callback1---------\n");
}
static void callback2()
{
	printf("--------callback2---------\n");
}
static void __attribute__ ((constructor)) before_main(void)
{
	printf("--------before main---------\n");
}
static void __attribute__ ((destructor)) after_main(void)
{
	printf("--------after main---------\n");
}
int main(void)
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"fputs use fill buffer"};
	//char buf[]={"Hello World\n"};
	//不加\n
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs!\n");
		return -1;		
	}
	printf("-----------running in main !-------------------\n");
	printf("printf use line buffer");
	//printf默认行缓存,标准输出是行缓存，如果没有遇到“\n”，则需要写满缓存区才能执行I/O操作
	//printf未输出换行符前的缓存在调用_exit后会被清空从而无法输出，而使用exit则会输出

	exit(0);		//无论全缓冲，行缓冲，printf都能显示，buf也能写入文件
	//_exit(0);		//无论全缓冲，行缓冲buf都无法写入文件，但是对于printf。行缓冲能显示，全缓冲无法显示。
	//return(0);
}
