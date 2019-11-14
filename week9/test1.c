#include "my.h"
static void __attribute__((constructor)) before_main(){
	printf("before test1 main!\n");
}

int main(int argc,char *argv[])
{
	int i;
//atexit(callback1);
//atexit(callback2);
//atexit(callback3);
	printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
	for(i=0;i<argc;i++)
		printf("test1 : %d : %s \n",i,argv[i]);
//printf("test2 Main function finished!\n");
	sleep(20);
	return 0;
}

