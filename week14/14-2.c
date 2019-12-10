#include "my.h"
int main()
{
	pid_t pid;
	int i,ret;
	struct timeval tv1,tv2;
	struct timezone tz;
	gittimeofday(&tv1,&tz);
	for(i=0;i<100000;i++)
	{
		pid = fork();
	}
	gittimeofday(&tv2,&tz);
	printf("running time is %ld\n",tv2.tv_usec-tv1.tv_usec);
	return 0;
} 
