#include "my.h"

int main()
{
	printf("caller3 pid = %d,ppid=%d\n",getpid(),getppid());
	execl ("/home/rlk/LinuxWorkspace/week9/test1","./test1","hello","world",NULL);
	printf("excel after calling!\n");

}
