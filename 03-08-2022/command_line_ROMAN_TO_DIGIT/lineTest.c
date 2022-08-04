#include<stdio.h>

int main()
{
	FILE *fptr = NULL;
	char *line;
	size_t n=0;
	
	fptr = fopen("input.txt", "r");
	
	while(getline(&line, &n, fptr) != -1)
	{
		printf("%s", line);
	}
	
	printf("END\n");
	
	fclose(fptr);
	
	return 0;
	

}
