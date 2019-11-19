#include "my.h"
//验证僵尸程序
int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("failed fork!\n");
		return -1;
	}
	else if(pid==0){
		printf("child %d is run!\n",getpid());
		printf("child will exit!\n");
		exit(120);	
	}else{
		printf("parent is waiting child %d to exit!\n ",pid);
		sleep(100);
		printf("parent %d is run!\n",getpid());
	}
}
