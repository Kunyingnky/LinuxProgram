#include "my.h"

int main()
{
	char *arg[]={"./test1","123","hello","world",NULL};
	printf("caller3 pid = %d,ppid=%d\n",getpid(),getppid());
	execv ("/home/rlk/LinuxWorkspace/week9/test1",arg);
	printf("excel after calling!\n");
	return 0;
}
