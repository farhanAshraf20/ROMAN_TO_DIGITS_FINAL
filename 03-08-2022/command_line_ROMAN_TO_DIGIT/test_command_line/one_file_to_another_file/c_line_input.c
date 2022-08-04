#include<stdio.h>


int main(int argc, char* argv[])
{
	//printf("No of argument : %d \n",argc);
	//printf("Argument No1 :%s \n",*argv);
	*argv = *(argv+1);
	printf("Argument No2 :%s \n",*argv);

return 0;
}
