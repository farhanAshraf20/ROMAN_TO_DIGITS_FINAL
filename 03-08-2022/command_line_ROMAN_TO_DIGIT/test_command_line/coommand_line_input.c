#include<stdio.h>

int main(int argc, char* argv[])
{
	char *a;
	printf("No of argument : %d \n",argc);
	printf("Argument No1 :%s \n",*argv);
	//*argv = *(argv+1);
	printf("Argument No2 :%s \n",argv[1]);
	a=argv[1];
	printf("Argument No2... :%s \n",a);
	printf("Argument No2 :%d \n",strlen(a));	

return 0;
}
