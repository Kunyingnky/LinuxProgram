#include <stdio.h>
int main()
{
	//修改缓存方式，将缓存类型改为无缓存
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello");
	/*for(int i=0;i<1024;i++)
	{
		printf("a");
	}*/
	
	while(1);
}
