#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[],char *env[])
{
	int i=0,j=0;
	extern char **environ;
	for(;env[i];i++)
	{
		printf("%s\n",env[i]);
	}
	for(;environ[i];i++)
	{
		printf("%s\n",environ[i]);
	}
	printf("%s\n",getenv("PATH"));
}
