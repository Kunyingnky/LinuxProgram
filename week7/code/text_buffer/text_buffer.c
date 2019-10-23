#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char buf[] = {"1234 stdout\n"};
int main(){

//父子进程拥有相同的代码，但可通过fork()返回值不同
	pid_t id;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		perror("can't write");
	printf("ABCDEF");    //第一种情况：printf不加\n 表示使用全缓冲形式，输出后不清空
	id = fork();
	if(id<0)
		perror("fork error");
	exit(0);
}
